#include "interface.h"
#include <pthread.h>

typedef struct { int64_t* a; size_t n; } tim_job_t;
static void* tim_w(void* p) {
    tim_job_t* j = (tim_job_t*)p;
    timsort_merge_gallop_sort(j->a, j->n);
    return NULL;
}
timsort_merge_gallop_err_t timsort_merge_gallop_batch_mt(int64_t** arrays, const size_t* lens, size_t k) {
    if (!arrays || !lens) return TIMSORT_MERGE_GALLOP_ERR_NULL;
    if (k > 8) k = 8;
    pthread_t th[8]; tim_job_t jb[8];
    for (size_t i = 0; i < k; ++i) { jb[i] = (tim_job_t){arrays[i], lens[i]}; pthread_create(&th[i], NULL, tim_w, &jb[i]); }
    for (size_t i = 0; i < k; ++i) pthread_join(th[i], NULL);
    return TIMSORT_MERGE_GALLOP_OK;
}
