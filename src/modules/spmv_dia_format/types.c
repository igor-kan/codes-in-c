/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format | Algorithm Family: sparse_math
 */

#ifndef SPMV_DIA_FORMAT_TYPES_H
#define SPMV_DIA_FORMAT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SPMV_DIA_FORMAT_ALIGNMENT 64
#define SPMV_DIA_FORMAT_CAPACITY 4096

typedef struct spmv_dia_format_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} spmv_dia_format_config_t;

typedef struct spmv_dia_format_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    spmv_dia_format_config_t config;
} spmv_dia_format_state_t;

#endif /* SPMV_DIA_FORMAT_TYPES_H */
