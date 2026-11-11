/**
 * @file types.c
 * @brief Core types and configuration for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#ifndef SIMD_BIT_MATRIX_TRANSPOSE_TYPES_H
#define SIMD_BIT_MATRIX_TRANSPOSE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_BIT_MATRIX_TRANSPOSE_ALIGNMENT 64
#define SIMD_BIT_MATRIX_TRANSPOSE_DEFAULT_SZ 8192

typedef struct simd_bit_matrix_transpose_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_bit_matrix_transpose_config_t;

typedef struct simd_bit_matrix_transpose_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_bit_matrix_transpose_config_t config;
} simd_bit_matrix_transpose_state_t;

#endif /* SIMD_BIT_MATRIX_TRANSPOSE_TYPES_H */
