/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Vectorized Float64 Dot Product and Euclidean Norm.
 * Module: simd_vector_math
 */

#ifndef SIMD_VECTOR_MATH_TYPES_H
#define SIMD_VECTOR_MATH_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIMD_VECTOR_MATH_ALIGNMENT 64
#define SIMD_VECTOR_MATH_SUCCESS 0
#define SIMD_VECTOR_MATH_ERR_NULL_PTR -1
#define SIMD_VECTOR_MATH_ERR_INVALID_PARAM -2
#define SIMD_VECTOR_MATH_ERR_OUT_OF_BOUNDS -3

typedef struct simd_vector_math_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} simd_vector_math_config_t;

typedef struct simd_vector_math_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    simd_vector_math_config_t config;
} simd_vector_math_context_t;

int simd_vector_math_init(simd_vector_math_context_t* ctx, const simd_vector_math_config_t* cfg);
int simd_vector_math_destroy(simd_vector_math_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* SIMD_VECTOR_MATH_TYPES_H */
