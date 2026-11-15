#include "interface.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    const uint8_t** bufs;
    const size_t* lens;
    uint64_t* out_hashes;
    size_t start;
    size_t end;
    uint64_t seed;
} xxh_worker_args_t;

static void* xxh_worker(void* arg) {
    xxh_worker_args_t* w = (xxh_worker_args_t*)arg;
    for (size_t i = w->start; i < w->end; ++i) {
        w->out_hashes[i] = xxhash64_streaming_oneshot(w->bufs[i], w->lens[i], w->seed);
    }
    return NULL;
}

xxhash64_streaming_err_t xxhash64_streaming_batch_mt(const uint8_t** bufs, const size_t* lens, uint64_t* out_hashes, size_t n_items, uint64_t seed, size_t num_threads) {
    if (!bufs || !lens || !out_hashes) return XXHASH64_STREAMING_ERR_NULL;
    if (n_items == 0) return XXHASH64_STREAMING_OK;
    if (num_threads <= 1 || n_items < 4) {
        for (size_t i = 0; i < n_items; ++i) out_hashes[i] = xxhash64_streaming_oneshot(bufs[i], lens[i], seed);
        return XXHASH64_STREAMING_OK;
    }
    if (num_threads > 8) num_threads = 8;
    if (num_threads > n_items) num_threads = n_items;
    pthread_t threads[8];
    xxh_worker_args_t args[8];
    size_t chunk = (n_items + num_threads - 1) / num_threads;
    size_t created = 0;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * chunk;
        size_t e = s + chunk;
        if (s >= n_items) break;
        if (e > n_items) e = n_items;
        args[t] = (xxh_worker_args_t){bufs, lens, out_hashes, s, e, seed};
        pthread_create(&threads[t], NULL, xxh_worker, &args[t]);
        created++;
    }
    for (size_t t = 0; t < created; ++t) pthread_join(threads[t], NULL);
    return XXHASH64_STREAMING_OK;
}
