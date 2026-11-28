#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} dary_heap_c11_d61_task_t;

static void* dary_heap_c11_d61_worker(void* raw) {
    dary_heap_c11_d61_task_t* t = (dary_heap_c11_d61_task_t*)raw;
    t->out = dary_heap_c11_d61_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t dary_heap_c11_d61_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    dary_heap_c11_d61_task_t ta = {a, na, 0};
    dary_heap_c11_d61_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, dary_heap_c11_d61_worker, &ta);
    pthread_create(&th2, NULL, dary_heap_c11_d61_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
