/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random | Algorithm Family: random_gen
 */

#ifndef PCG64_RANDOM_TYPES_H
#define PCG64_RANDOM_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define PCG64_RANDOM_ALIGNMENT 64
#define PCG64_RANDOM_BASE_CAPACITY 1024

typedef struct pcg64_random_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} pcg64_random_config_t;

typedef struct pcg64_random_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    pcg64_random_config_t config;
} pcg64_random_state_t;

#endif /* PCG64_RANDOM_TYPES_H */
