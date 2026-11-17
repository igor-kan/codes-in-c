#include "interface.h"
#include <pthread.h>

typedef struct { scalar_fn_t f; const double* br; size_t lo; size_t hi; double tol; brent_result_t* out; } br_arg_t;

static void* br_worker(void* raw) {
    br_arg_t* a = (br_arg_t*)raw;
    for (size_t i = a->lo; i < a->hi; ++i) {
        brent_solve(a->f, NULL, a->br[2 * i], a->br[2 * i + 1], a->tol, 100, &a->out[i]);
    }
    return NULL;
}

void brent_parallel_solve(scalar_fn_t f, const double* brackets, size_t n_pairs, double tol, brent_result_t* out) {
    size_t mid = n_pairs / 2;
    br_arg_t args[2] = {{f, brackets, 0, mid, tol, out}, {f, brackets, mid, n_pairs, tol, out}};
    pthread_t t1, t2;
    pthread_create(&t1, NULL, br_worker, &args[0]);
    pthread_create(&t2, NULL, br_worker, &args[1]);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
