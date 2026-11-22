#include "interface.h"
#include <pthread.h>

typedef struct {
    const uint64_t* ptr;
    size_t len;
    uint64_t out;
} utf8_dfa_valid_c11_d57_task_t;

static void* utf8_dfa_valid_c11_d57_worker(void* raw) {
    utf8_dfa_valid_c11_d57_task_t* t = (utf8_dfa_valid_c11_d57_task_t*)raw;
    t->out = utf8_dfa_valid_c11_d57_fast_fold_u64(t->ptr, t->len);
    return NULL;
}

uint64_t utf8_dfa_valid_c11_d57_parallel_fold_pair(const uint64_t* a, size_t na, const uint64_t* b, size_t nb) {
    utf8_dfa_valid_c11_d57_task_t ta = {a, na, 0};
    utf8_dfa_valid_c11_d57_task_t tb = {b, nb, 0};
    pthread_t th1, th2;
    pthread_create(&th1, NULL, utf8_dfa_valid_c11_d57_worker, &ta);
    pthread_create(&th2, NULL, utf8_dfa_valid_c11_d57_worker, &tb);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return ta.out ^ tb.out;
}
