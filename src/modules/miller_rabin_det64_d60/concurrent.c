#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} miller_rabin_det64_d60_task_t;

static void* miller_rabin_det64_d60_worker(void* raw) {
    miller_rabin_det64_d60_task_t* t = (miller_rabin_det64_d60_task_t*)raw;
    t->out = miller_rabin_det64_d60_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t miller_rabin_det64_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    miller_rabin_det64_d60_task_t ta = {a, na, 0};
    miller_rabin_det64_d60_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, miller_rabin_det64_d60_worker, &ta);
    pthread_create(&th2, NULL, miller_rabin_det64_d60_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
