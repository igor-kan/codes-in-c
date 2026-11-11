/**
 * @file types.c
 * @brief Core types and configuration for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#ifndef FAST_FOURIER_BLUESTEIN_TYPES_H
#define FAST_FOURIER_BLUESTEIN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_FOURIER_BLUESTEIN_ALIGNMENT 64
#define FAST_FOURIER_BLUESTEIN_DEFAULT_SZ 8192

typedef struct fast_fourier_bluestein_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} fast_fourier_bluestein_config_t;

typedef struct fast_fourier_bluestein_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    fast_fourier_bluestein_config_t config;
} fast_fourier_bluestein_state_t;

#endif /* FAST_FOURIER_BLUESTEIN_TYPES_H */
