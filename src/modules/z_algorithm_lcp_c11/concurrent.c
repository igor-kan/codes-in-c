#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} z_algorithm_lcp_c11_task_t;

static void* z_algorithm_lcp_c11_worker(void* raw) {
    z_algorithm_lcp_c11_task_t* t = (z_algorithm_lcp_c11_task_t*)raw;
    t->out = z_algorithm_lcp_c11_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t z_algorithm_lcp_c11_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    z_algorithm_lcp_c11_task_t ta = {a, na, 0};
    z_algorithm_lcp_c11_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, z_algorithm_lcp_c11_worker, &ta);
    pthread_create(&th2, NULL, z_algorithm_lcp_c11_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
