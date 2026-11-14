/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton | Algorithm Family: fast_math
 */

#ifndef FAST_SQRT_NEWTON_TYPES_H
#define FAST_SQRT_NEWTON_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_SQRT_NEWTON_ALIGNMENT 64
#define FAST_SQRT_NEWTON_CAPACITY 4096

typedef struct fast_sqrt_newton_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} fast_sqrt_newton_config_t;

typedef struct fast_sqrt_newton_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    fast_sqrt_newton_config_t config;
} fast_sqrt_newton_state_t;

#endif /* FAST_SQRT_NEWTON_TYPES_H */
