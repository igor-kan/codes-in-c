#ifndef BRENT_ROOT_C11_TYPES_H
#define BRENT_ROOT_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef double (*scalar_fn_t)(double x, void* ctx);

typedef struct {
    double root;
    double residual;
    int iters;
    bool converged;
} brent_result_t;

#endif /* BRENT_ROOT_C11_TYPES_H */
