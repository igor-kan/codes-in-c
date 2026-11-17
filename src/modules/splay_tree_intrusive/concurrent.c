#include "interface.h"
#include <pthread.h>

typedef struct { const int64_t* keys; size_t n; int64_t* out; } sp_arg_t;

static void* sp_worker(void* raw) {
    sp_arg_t* a = (sp_arg_t*)raw;
    splay_tree_t t;
    splay_init(&t);
    for (size_t i = 0; i < a->n; ++i) splay_insert(&t, a->keys[i], a->keys[i] * 2);
    *a->out = splay_fast_range_sum(&t, 0, 1000);
    return NULL;
}

void splay_parallel_queries(const int64_t* keys, size_t n, int64_t* out_sums) {
    size_t mid = n / 2;
    sp_arg_t args[2] = {{keys, mid, &out_sums[0]}, {keys + mid, n - mid, &out_sums[1]}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, sp_worker, &args[0]);
    pthread_create(&t2, NULL, sp_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
