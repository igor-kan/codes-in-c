/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#ifndef SIMD_FFT_RADIX4_INTERFACE_H
#define SIMD_FFT_RADIX4_INTERFACE_H

#include "types.c"

typedef int (*simd_fft_radix4_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_fft_radix4_vtable {
    int (*init)(simd_fft_radix4_state_t* state, const simd_fft_radix4_config_t* cfg);
    int (*execute)(simd_fft_radix4_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(simd_fft_radix4_state_t* state);
} simd_fft_radix4_vtable_t;

#endif /* SIMD_FFT_RADIX4_INTERFACE_H */
