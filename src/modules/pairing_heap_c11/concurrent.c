#include "interface.h"
#include <pthread.h>

typedef struct { int64_t* a; size_t n; } sort_arg_t;

static void* worker_sort(void* raw) {
    sort_arg_t* arg = (sort_arg_t*)raw;
    ph_fast_sort(arg->a, arg->n);
    return NULL;
}

void ph_parallel_sort_pair(int64_t* a, size_t na, int64_t* b, size_t nb) {
    sort_arg_t args[2] = {{a, na}, {b, nb}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, worker_sort, &args[0]);
    pthread_create(&t2, NULL, worker_sort, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
