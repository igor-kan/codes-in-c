#include "interface.h"
#include <pthread.h>

typedef struct { uint32_t* p; size_t n; } rsort_arg_t;

static void* rsort_worker(void* raw) {
    rsort_arg_t* a = (rsort_arg_t*)raw;
    msd_radix_sort(a->p, a->n, (msd_config_t){16});
    return NULL;
}

void msd_parallel_sort_halves(uint32_t* a, size_t na, uint32_t* b, size_t nb) {
    rsort_arg_t args[2] = {{a, na}, {b, nb}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, rsort_worker, &args[0]);
    pthread_create(&t2, NULL, rsort_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
