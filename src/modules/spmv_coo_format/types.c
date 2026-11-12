/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format | Algorithm Family: sparse_math
 */

#ifndef SPMV_COO_FORMAT_TYPES_H
#define SPMV_COO_FORMAT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SPMV_COO_FORMAT_ALIGNMENT 64
#define SPMV_COO_FORMAT_BASE_CAPACITY 1024

typedef struct spmv_coo_format_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} spmv_coo_format_config_t;

typedef struct spmv_coo_format_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    spmv_coo_format_config_t config;
} spmv_coo_format_state_t;

#endif /* SPMV_COO_FORMAT_TYPES_H */
