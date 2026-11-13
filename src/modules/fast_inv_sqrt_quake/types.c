/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake | Algorithm Family: fast_math
 */

#ifndef FAST_INV_SQRT_QUAKE_TYPES_H
#define FAST_INV_SQRT_QUAKE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_INV_SQRT_QUAKE_ALIGNMENT 64
#define FAST_INV_SQRT_QUAKE_CAPACITY 2048

typedef struct fast_inv_sqrt_quake_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} fast_inv_sqrt_quake_config_t;

typedef struct fast_inv_sqrt_quake_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    fast_inv_sqrt_quake_config_t config;
} fast_inv_sqrt_quake_state_t;

#endif /* FAST_INV_SQRT_QUAKE_TYPES_H */
