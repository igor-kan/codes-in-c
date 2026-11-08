/**
 * @file types.c
 * @brief Core type definitions and operational interfaces for Cache-Blocked Matrix GEMM with Loop Tiling.
 * Module: matrix_blocked_gemm
 */

#ifndef MATRIX_BLOCKED_GEMM_TYPES_H
#define MATRIX_BLOCKED_GEMM_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MATRIX_BLOCKED_GEMM_ALIGNMENT 64
#define MATRIX_BLOCKED_GEMM_SUCCESS 0
#define MATRIX_BLOCKED_GEMM_ERR_NULL_PTR -1
#define MATRIX_BLOCKED_GEMM_ERR_INVALID_PARAM -2
#define MATRIX_BLOCKED_GEMM_ERR_OUT_OF_BOUNDS -3

typedef struct matrix_blocked_gemm_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} matrix_blocked_gemm_config_t;

typedef struct matrix_blocked_gemm_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    matrix_blocked_gemm_config_t config;
} matrix_blocked_gemm_context_t;

int matrix_blocked_gemm_init(matrix_blocked_gemm_context_t* ctx, const matrix_blocked_gemm_config_t* cfg);
int matrix_blocked_gemm_destroy(matrix_blocked_gemm_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* MATRIX_BLOCKED_GEMM_TYPES_H */
