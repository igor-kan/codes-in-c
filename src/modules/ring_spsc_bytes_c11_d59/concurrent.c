#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} ring_spsc_bytes_c11_d59_task_t;

static void* ring_spsc_bytes_c11_d59_worker(void* raw) {
    ring_spsc_bytes_c11_d59_task_t* t = (ring_spsc_bytes_c11_d59_task_t*)raw;
    t->out = ring_spsc_bytes_c11_d59_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t ring_spsc_bytes_c11_d59_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    ring_spsc_bytes_c11_d59_task_t ta = {a, na, 0};
    ring_spsc_bytes_c11_d59_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, ring_spsc_bytes_c11_d59_worker, &ta);
    pthread_create(&th2, NULL, ring_spsc_bytes_c11_d59_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
