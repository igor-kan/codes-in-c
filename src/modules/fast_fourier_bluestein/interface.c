/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#ifndef FAST_FOURIER_BLUESTEIN_INTERFACE_H
#define FAST_FOURIER_BLUESTEIN_INTERFACE_H

#include "types.c"

typedef int (*fast_fourier_bluestein_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct fast_fourier_bluestein_vtable {
    int (*init)(fast_fourier_bluestein_state_t* state, const fast_fourier_bluestein_config_t* cfg);
    int (*execute)(fast_fourier_bluestein_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(fast_fourier_bluestein_state_t* state);
    int (*destroy)(fast_fourier_bluestein_state_t* state);
} fast_fourier_bluestein_vtable_t;

#endif /* FAST_FOURIER_BLUESTEIN_INTERFACE_H */
