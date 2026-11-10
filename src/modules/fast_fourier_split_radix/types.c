/**
 * @file types.c
 * @brief Core types and configuration for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#ifndef FAST_FOURIER_SPLIT_RADIX_TYPES_H
#define FAST_FOURIER_SPLIT_RADIX_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_FOURIER_SPLIT_RADIX_ALIGNMENT 64
#define FAST_FOURIER_SPLIT_RADIX_CAPACITY 4096

typedef struct fast_fourier_split_radix_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} fast_fourier_split_radix_config_t;

typedef struct fast_fourier_split_radix_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    fast_fourier_split_radix_config_t config;
} fast_fourier_split_radix_state_t;

#endif /* FAST_FOURIER_SPLIT_RADIX_TYPES_H */
