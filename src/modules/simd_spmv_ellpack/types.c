/**
 * @file types.c
 * @brief Core types and configuration for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#ifndef SIMD_SPMV_ELLPACK_TYPES_H
#define SIMD_SPMV_ELLPACK_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_SPMV_ELLPACK_ALIGNMENT 64
#define SIMD_SPMV_ELLPACK_CAPACITY 4096

typedef struct simd_spmv_ellpack_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_spmv_ellpack_config_t;

typedef struct simd_spmv_ellpack_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_spmv_ellpack_config_t config;
} simd_spmv_ellpack_state_t;

#endif /* SIMD_SPMV_ELLPACK_TYPES_H */
