/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton | Algorithm Family: fast_math
 */

#ifndef FAST_SQRT_NEWTON_INTERFACE_H
#define FAST_SQRT_NEWTON_INTERFACE_H

#include "types.c"

typedef int (*fast_sqrt_newton_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct fast_sqrt_newton_vtable {
    int (*init)(fast_sqrt_newton_state_t* state, const fast_sqrt_newton_config_t* cfg);
    int (*execute)(fast_sqrt_newton_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_sqrt_newton_state_t* state);
    int (*destroy)(fast_sqrt_newton_state_t* state);
} fast_sqrt_newton_vtable_t;

#endif /* FAST_SQRT_NEWTON_INTERFACE_H */
