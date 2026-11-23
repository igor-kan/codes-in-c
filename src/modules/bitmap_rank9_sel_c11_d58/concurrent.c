#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} bitmap_rank9_sel_c11_d58_task_t;

static void* bitmap_rank9_sel_c11_d58_worker(void* raw) {
    bitmap_rank9_sel_c11_d58_task_t* t = (bitmap_rank9_sel_c11_d58_task_t*)raw;
    t->out = bitmap_rank9_sel_c11_d58_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t bitmap_rank9_sel_c11_d58_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    bitmap_rank9_sel_c11_d58_task_t ta = {a, na, 0};
    bitmap_rank9_sel_c11_d58_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, bitmap_rank9_sel_c11_d58_worker, &ta);
    pthread_create(&th2, NULL, bitmap_rank9_sel_c11_d58_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
