/**
 * @file types.c
 * @brief Core types and configuration for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#ifndef SIMD_MATRIX_TRANSPOSE_TYPES_H
#define SIMD_MATRIX_TRANSPOSE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_MATRIX_TRANSPOSE_ALIGNMENT 64
#define SIMD_MATRIX_TRANSPOSE_DEFAULT_CAPACITY 1024

typedef struct simd_matrix_transpose_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_matrix_transpose_config_t;

typedef struct simd_matrix_transpose_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    simd_matrix_transpose_config_t config;
} simd_matrix_transpose_state_t;

#endif /* SIMD_MATRIX_TRANSPOSE_TYPES_H */
