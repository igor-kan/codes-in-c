/**
 * @file types.c
 * @brief Core types and configuration for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#ifndef SIMD_FFT_RADIX4_TYPES_H
#define SIMD_FFT_RADIX4_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_FFT_RADIX4_ALIGNMENT 64
#define SIMD_FFT_RADIX4_CAPACITY 2048

typedef struct simd_fft_radix4_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_fft_radix4_config_t;

typedef struct simd_fft_radix4_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_fft_radix4_config_t config;
} simd_fft_radix4_state_t;

#endif /* SIMD_FFT_RADIX4_TYPES_H */
