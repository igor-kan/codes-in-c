#include "interface.h"
#include <pthread.h>

typedef struct { const llrb_tree_t* t; const int64_t* probes; size_t n; int32_t hits; } rb_arg_t;

static void* rb_worker(void* raw) {
    rb_arg_t* a = (rb_arg_t*)raw;
    int32_t h = 0;
    for (size_t i = 0; i < a->n; ++i) {
        if (llrb_get(a->t, a->probes[i], NULL)) h++;
    }
    a->hits = h;
    return NULL;
}

int32_t llrb_parallel_count_present(const llrb_tree_t* t, const int64_t* probes, size_t n) {
    size_t mid = n / 2;
    rb_arg_t args[2] = {{t, probes, mid, 0}, {t, probes + mid, n - mid, 0}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, rb_worker, &args[0]);
    pthread_create(&t2, NULL, rb_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return args[0].hits + args[1].hits;
}
