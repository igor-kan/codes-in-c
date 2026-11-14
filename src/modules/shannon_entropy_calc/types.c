/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc | Algorithm Family: statistics
 */

#ifndef SHANNON_ENTROPY_CALC_TYPES_H
#define SHANNON_ENTROPY_CALC_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHANNON_ENTROPY_CALC_ALIGNMENT 64
#define SHANNON_ENTROPY_CALC_CAPACITY 4096

typedef struct shannon_entropy_calc_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} shannon_entropy_calc_config_t;

typedef struct shannon_entropy_calc_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    shannon_entropy_calc_config_t config;
} shannon_entropy_calc_state_t;

#endif /* SHANNON_ENTROPY_CALC_TYPES_H */
