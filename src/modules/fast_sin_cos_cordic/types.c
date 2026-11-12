/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic | Algorithm Family: cordic
 */

#ifndef FAST_SIN_COS_CORDIC_TYPES_H
#define FAST_SIN_COS_CORDIC_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_SIN_COS_CORDIC_ALIGNMENT 64
#define FAST_SIN_COS_CORDIC_BASE_CAPACITY 1024

typedef struct fast_sin_cos_cordic_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} fast_sin_cos_cordic_config_t;

typedef struct fast_sin_cos_cordic_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    fast_sin_cos_cordic_config_t config;
} fast_sin_cos_cordic_state_t;

#endif /* FAST_SIN_COS_CORDIC_TYPES_H */
