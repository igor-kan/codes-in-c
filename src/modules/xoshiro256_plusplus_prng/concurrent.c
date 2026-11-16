#include "interface.h"
#include <pthread.h>

typedef struct {
    xoshiro256pp_state_t st;
    size_t count;
    uint64_t acc;
} xo_job_t;

static void* xo_worker(void* arg) {
    xo_job_t* j = (xo_job_t*)arg;
    uint64_t a = 0;
    for (size_t i = 0; i < j->count; ++i) a ^= xoshiro_next(&j->st);
    j->acc = a;
    return NULL;
}

xoshiro256_plusplus_prng_err_t xoshiro_parallel_reduce_mt(uint64_t seed, size_t words_per_thread, uint64_t* xor_out, size_t num_threads) {
    if (!xor_out) return XOSHIRO256_PLUSPLUS_PRNG_ERR_NULL;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    xoshiro256pp_state_t base;
    xoshiro_seed(&base, seed);
    pthread_t th[4];
    xo_job_t jobs[4];
    for (size_t t = 0; t < num_threads; ++t) {
        jobs[t].st = base;
        jobs[t].count = words_per_thread;
        jobs[t].acc = 0;
        xoshiro_jump(&base);
        pthread_create(&th[t], NULL, xo_worker, &jobs[t]);
    }
    uint64_t total = 0;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        total ^= jobs[t].acc;
    }
    *xor_out = total;
    return XOSHIRO256_PLUSPLUS_PRNG_OK;
}
