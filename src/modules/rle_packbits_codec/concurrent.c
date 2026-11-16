#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint8_t** srcs;
    const size_t* lens;
    size_t s;
    size_t e;
    int ok;
} pb_arg_t;

static void* pb_worker(void* arg) {
    pb_arg_t* p = (pb_arg_t*)arg;
    for (size_t i = p->s; i < p->e; ++i) {
        if (packbits_verify_roundtrip(p->srcs[i], p->lens[i]) != RLE_PACKBITS_CODEC_OK) p->ok = 0;
    }
    return NULL;
}

rle_packbits_codec_err_t packbits_batch_mt(const uint8_t** srcs, const size_t* lens, size_t n_items, size_t num_threads) {
    if (!srcs || !lens) return RLE_PACKBITS_CODEC_ERR_NULL;
    if (n_items == 0) return RLE_PACKBITS_CODEC_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    pb_arg_t args[4];
    size_t step = (n_items + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > n_items) e = n_items;
        args[t] = (pb_arg_t){srcs, lens, s, e, 1};
        pthread_create(&th[t], NULL, pb_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? RLE_PACKBITS_CODEC_OK : RLE_PACKBITS_CODEC_ERR_INVARIANT;
}
