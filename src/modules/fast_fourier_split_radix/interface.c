/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#ifndef FAST_FOURIER_SPLIT_RADIX_INTERFACE_H
#define FAST_FOURIER_SPLIT_RADIX_INTERFACE_H

#include "types.c"

typedef int (*fast_fourier_split_radix_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct fast_fourier_split_radix_vtable {
    int (*init)(fast_fourier_split_radix_state_t* state, const fast_fourier_split_radix_config_t* cfg);
    int (*execute)(fast_fourier_split_radix_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_fourier_split_radix_state_t* state);
    int (*destroy)(fast_fourier_split_radix_state_t* state);
} fast_fourier_split_radix_vtable_t;

#endif /* FAST_FOURIER_SPLIT_RADIX_INTERFACE_H */
