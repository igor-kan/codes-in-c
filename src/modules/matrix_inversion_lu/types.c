/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu | Algorithm Family: linear_algebra
 */

#ifndef MATRIX_INVERSION_LU_TYPES_H
#define MATRIX_INVERSION_LU_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MATRIX_INVERSION_LU_ALIGNMENT 64
#define MATRIX_INVERSION_LU_CAPACITY 4096

typedef struct matrix_inversion_lu_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} matrix_inversion_lu_config_t;

typedef struct matrix_inversion_lu_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    matrix_inversion_lu_config_t config;
} matrix_inversion_lu_state_t;

#endif /* MATRIX_INVERSION_LU_TYPES_H */
