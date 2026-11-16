#include "interface.h"
#include <pthread.h>

typedef struct {
    const skiplist_t* sl;
    const int64_t* keys;
    int64_t* out_vals;
    size_t s;
    size_t e;
} sl_search_job_t;

static void* sl_worker(void* arg) {
    sl_search_job_t* j = (sl_search_job_t*)arg;
    for (size_t i = j->s; i < j->e; ++i) {
        int64_t v = -1;
        j->out_vals[i] = sl_find(j->sl, j->keys[i], &v) ? v : -1;
    }
    return NULL;
}

skip_list_probabilistic_err_t sl_batch_search_mt(const skiplist_t* sl, const int64_t* keys, int64_t* out_vals, size_t n_keys, size_t num_threads) {
    if (!sl || !keys || !out_vals) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    if (n_keys == 0) return SKIP_LIST_PROBABILISTIC_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    sl_search_job_t jobs[4];
    size_t chunk = (n_keys + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * chunk, e = s + chunk;
        if (e > n_keys) e = n_keys;
        jobs[t] = (sl_search_job_t){sl, keys, out_vals, s, e};
        pthread_create(&th[t], NULL, sl_worker, &jobs[t]);
    }
    for (size_t t = 0; t < num_threads; ++t) pthread_join(th[t], NULL);
    return SKIP_LIST_PROBABILISTIC_OK;
}
