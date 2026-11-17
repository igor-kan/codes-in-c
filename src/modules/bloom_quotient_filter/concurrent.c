#include "interface.h"
#include <pthread.h>

typedef struct { const quotient_filter_t* qf; const uint64_t* keys; size_t n; size_t hits; } qf_arg_t;

static void* qf_worker(void* raw) {
    qf_arg_t* a = (qf_arg_t*)raw;
    size_t h = 0;
    for (size_t i = 0; i < a->n; ++i) {
        if (qf_may_contain(a->qf, a->keys[i])) h++;
    }
    a->hits = h;
    return NULL;
}

size_t qf_parallel_probe_hits(const quotient_filter_t* qf, const uint64_t* keys, size_t n) {
    size_t mid = n / 2;
    qf_arg_t args[2] = {{qf, keys, mid, 0}, {qf, keys + mid, n - mid, 0}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, qf_worker, &args[0]);
    pthread_create(&t2, NULL, qf_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return args[0].hits + args[1].hits;
}
