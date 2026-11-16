#include "interface.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t k;
    size_t stream_len;
    size_t trials;
    uint64_t seed_base;
    uint64_t* local_freq;
} res_trial_arg_t;

static void* res_worker(void* arg) {
    res_trial_arg_t* a = (res_trial_arg_t*)arg;
    int64_t* buf = (int64_t*)malloc(a->k * sizeof(int64_t));
    if (!buf) return NULL;
    for (size_t t = 0; t < a->trials; ++t) {
        reservoir_t r;
        reservoir_init(&r, buf, a->k, a->seed_base + (uint64_t)t * 10007ULL);
        for (size_t v = 0; v < a->stream_len; ++v) reservoir_observe(&r, (int64_t)v);
        for (size_t j = 0; j < r.filled; ++j) a->local_freq[r.items[j]]++;
    }
    free(buf);
    return NULL;
}

reservoir_sampling_vitter_err_t reservoir_mt_histogram(size_t k, size_t stream_len, size_t trials, uint64_t* freq_out, size_t num_threads) {
    if (!freq_out) return RESERVOIR_SAMPLING_VITTER_ERR_NULL;
    if (k == 0 || stream_len < k || trials == 0) return RESERVOIR_SAMPLING_VITTER_ERR_BOUNDS;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    memset(freq_out, 0, stream_len * sizeof(uint64_t));
    pthread_t th[4];
    res_trial_arg_t args[4];
    size_t per = trials / num_threads, rem = trials % num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        args[t].k = k;
        args[t].stream_len = stream_len;
        args[t].trials = per + (t < rem ? 1U : 0U);
        args[t].seed_base = 0x10000ULL * (uint64_t)(t + 1);
        args[t].local_freq = (uint64_t*)calloc(stream_len, sizeof(uint64_t));
        pthread_create(&th[t], NULL, res_worker, &args[t]);
    }
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        for (size_t v = 0; v < stream_len; ++v) freq_out[v] += args[t].local_freq[v];
        free(args[t].local_freq);
    }
    return RESERVOIR_SAMPLING_VITTER_OK;
}
