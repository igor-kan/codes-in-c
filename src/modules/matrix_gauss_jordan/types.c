/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan | Algorithm Family: linear_algebra
 */

#ifndef MATRIX_GAUSS_JORDAN_TYPES_H
#define MATRIX_GAUSS_JORDAN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MATRIX_GAUSS_JORDAN_ALIGNMENT 64
#define MATRIX_GAUSS_JORDAN_BASE_CAPACITY 1024

typedef struct matrix_gauss_jordan_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} matrix_gauss_jordan_config_t;

typedef struct matrix_gauss_jordan_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    matrix_gauss_jordan_config_t config;
} matrix_gauss_jordan_state_t;

#endif /* MATRIX_GAUSS_JORDAN_TYPES_H */
