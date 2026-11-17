#include "interface.h"
#include <pthread.h>

typedef struct { int64_t* arr; size_t n; uint64_t seed; } shuf_arg_t;

static void* shuf_worker(void* raw) {
    shuf_arg_t* a = (shuf_arg_t*)raw;
    fisher_yates_shuffle(a->arr, a->n, a->seed);
    return NULL;
}

void parallel_independent_shuffles(int64_t* a, int64_t* b, size_t n, uint64_t seed) {
    shuf_arg_t args[2] = {{a, n, seed}, {b, n, seed ^ 0x9e3779b97f4a7c15ULL}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, shuf_worker, &args[0]);
    pthread_create(&t2, NULL, shuf_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
