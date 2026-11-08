/**
 * @file types.c
 * @brief Core types and configuration for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

#ifndef BARYCENTRIC_INTERPOLATION_TYPES_H
#define BARYCENTRIC_INTERPOLATION_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BARYCENTRIC_INTERPOLATION_ALIGNMENT 64
#define BARYCENTRIC_INTERPOLATION_DEFAULT_CAPACITY 1024

typedef struct barycentric_interpolation_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} barycentric_interpolation_config_t;

typedef struct barycentric_interpolation_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    barycentric_interpolation_config_t config;
} barycentric_interpolation_state_t;

#endif /* BARYCENTRIC_INTERPOLATION_TYPES_H */
