#include "interface.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const uint8_t** srcs;
    const size_t* lens;
    size_t start;
    size_t end;
    int ok;
} cobs_worker_t;

static void* cobs_worker(void* arg) {
    cobs_worker_t* w = (cobs_worker_t*)arg;
    for (size_t i = w->start; i < w->end; ++i) {
        size_t cap = cobs_max_encoded_size(w->lens[i]);
        uint8_t* enc = (uint8_t*)malloc(cap);
        uint8_t* dec = (uint8_t*)malloc(w->lens[i] + 1U);
        size_t elen = 0, dlen = 0;
        if (!enc || !dec ||
            cobs_encode(w->srcs[i], w->lens[i], enc, cap, &elen) != COBS_FRAMING_CODEC_OK ||
            cobs_decode(enc, elen, dec, w->lens[i] + 1U, &dlen) != COBS_FRAMING_CODEC_OK ||
            dlen != w->lens[i] ||
            (dlen > 0 && memcmp(w->srcs[i], dec, dlen) != 0)) {
            w->ok = 0;
        }
        free(enc);
        free(dec);
    }
    return NULL;
}

cobs_framing_codec_err_t cobs_batch_roundtrip_mt(const uint8_t** srcs, const size_t* lens, size_t n_items, size_t num_threads) {
    if (!srcs || !lens) return COBS_FRAMING_CODEC_ERR_NULL;
    if (n_items == 0) return COBS_FRAMING_CODEC_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    cobs_worker_t args[4];
    size_t chunk = (n_items + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * chunk;
        size_t e = s + chunk;
        if (e > n_items) e = n_items;
        args[t] = (cobs_worker_t){srcs, lens, s, e, 1};
        pthread_create(&th[t], NULL, cobs_worker, &args[t]);
    }
    int all_ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) all_ok = 0;
    }
    return all_ok ? COBS_FRAMING_CODEC_OK : COBS_FRAMING_CODEC_ERR_INVARIANT;
}
