#include "interface.h"
#include <pthread.h>

typedef struct { const uint8_t* t; size_t n; const uint8_t* p; const bmh_table_t* tbl; size_t cnt; } bmh_arg_t;

static void* bmh_worker(void* raw) {
    bmh_arg_t* a = (bmh_arg_t*)raw;
    a->cnt = bmh_find_all(a->t, a->n, a->p, a->tbl, NULL, 0);
    return NULL;
}

size_t bmh_parallel_count(const uint8_t* text, size_t n, const uint8_t* pat, size_t m) {
    bmh_table_t tbl;
    if (bmh_compile(pat, m, &tbl) != BOYER_MOORE_HORSPOOL_C_OK || n < m) return 0;
    bmh_arg_t args[2] = {{text, n, pat, &tbl, 0}, {text, n, pat, &tbl, 0}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, bmh_worker, &args[0]);
    pthread_create(&t2, NULL, bmh_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return args[0].cnt;
}
