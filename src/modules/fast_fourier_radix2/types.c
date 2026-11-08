/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Cooley-Tukey In-Place Radix-2 FFT Engine.
 * Module: fast_fourier_radix2
 */

#ifndef FAST_FOURIER_RADIX2_TYPES_H
#define FAST_FOURIER_RADIX2_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FAST_FOURIER_RADIX2_ALIGNMENT 64
#define FAST_FOURIER_RADIX2_SUCCESS 0
#define FAST_FOURIER_RADIX2_ERR_NULL_PTR -1
#define FAST_FOURIER_RADIX2_ERR_INVALID_PARAM -2
#define FAST_FOURIER_RADIX2_ERR_OUT_OF_BOUNDS -3

typedef struct fast_fourier_radix2_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} fast_fourier_radix2_config_t;

typedef struct fast_fourier_radix2_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    fast_fourier_radix2_config_t config;
} fast_fourier_radix2_context_t;

int fast_fourier_radix2_init(fast_fourier_radix2_context_t* ctx, const fast_fourier_radix2_config_t* cfg);
int fast_fourier_radix2_destroy(fast_fourier_radix2_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* FAST_FOURIER_RADIX2_TYPES_H */
