#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} robin_hood_hash_d60_task_t;

static void* robin_hood_hash_d60_worker(void* raw) {
    robin_hood_hash_d60_task_t* t = (robin_hood_hash_d60_task_t*)raw;
    t->out = robin_hood_hash_d60_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t robin_hood_hash_d60_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    robin_hood_hash_d60_task_t ta = {a, na, 0};
    robin_hood_hash_d60_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, robin_hood_hash_d60_worker, &ta);
    pthread_create(&th2, NULL, robin_hood_hash_d60_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
