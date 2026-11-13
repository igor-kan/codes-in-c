/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake | Algorithm Family: fast_math
 */

#ifndef FAST_INV_SQRT_QUAKE_INTERFACE_H
#define FAST_INV_SQRT_QUAKE_INTERFACE_H

#include "types.c"

typedef int (*fast_inv_sqrt_quake_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct fast_inv_sqrt_quake_vtable {
    int (*init)(fast_inv_sqrt_quake_state_t* state, const fast_inv_sqrt_quake_config_t* cfg);
    int (*execute)(fast_inv_sqrt_quake_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_inv_sqrt_quake_state_t* state);
    int (*destroy)(fast_inv_sqrt_quake_state_t* state);
} fast_inv_sqrt_quake_vtable_t;

#endif /* FAST_INV_SQRT_QUAKE_INTERFACE_H */
