#include "interface.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    size_t s;
    size_t e;
    size_t n;
    const double* sub;
    const double* diag;
    const double* sup;
    const double* rhs;
    double* out;
    int ok;
} tdma_job_t;

static void* tdma_worker(void* arg) {
    tdma_job_t* j = (tdma_job_t*)arg;
    double* cp = (double*)malloc(j->n * sizeof(double));
    double* dp = (double*)malloc(j->n * sizeof(double));
    if (!cp || !dp) { free(cp); free(dp); j->ok = 0; return NULL; }
    for (size_t k = j->s; k < j->e; ++k) {
        if (tdma_solve(j->n, j->sub, j->diag, j->sup, j->rhs + k * j->n, j->out + k * j->n, cp, dp) != TRIDIAGONAL_THOMAS_C11_OK) {
            j->ok = 0;
        }
    }
    free(cp); free(dp);
    return NULL;
}

tridiagonal_thomas_c11_err_t tdma_batch_solve_mt(size_t n_systems, size_t n, const double* sub, const double* diag, const double* sup, const double* rhs_batch, double* x_batch, size_t num_threads) {
    if (!sub || !diag || !sup || !rhs_batch || !x_batch) return TRIDIAGONAL_THOMAS_C11_ERR_NULL;
    if (n_systems == 0 || n == 0) return TRIDIAGONAL_THOMAS_C11_OK;
    if (num_threads == 0) num_threads = 1;
    if (num_threads > 4) num_threads = 4;
    pthread_t th[4];
    tdma_job_t args[4];
    size_t step = (n_systems + num_threads - 1U) / num_threads;
    for (size_t t = 0; t < num_threads; ++t) {
        size_t s = t * step, e = s + step;
        if (e > n_systems) e = n_systems;
        args[t] = (tdma_job_t){s, e, n, sub, diag, sup, rhs_batch, x_batch, 1};
        pthread_create(&th[t], NULL, tdma_worker, &args[t]);
    }
    int ok = 1;
    for (size_t t = 0; t < num_threads; ++t) {
        pthread_join(th[t], NULL);
        if (!args[t].ok) ok = 0;
    }
    return ok ? TRIDIAGONAL_THOMAS_C11_OK : TRIDIAGONAL_THOMAS_C11_ERR_INVALID;
}
