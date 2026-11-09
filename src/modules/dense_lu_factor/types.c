/**
 * @file types.c
 * @brief Core types and configuration for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#ifndef DENSE_LU_FACTOR_TYPES_H
#define DENSE_LU_FACTOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define DENSE_LU_FACTOR_ALIGNMENT 64
#define DENSE_LU_FACTOR_CAPACITY 2048

typedef struct dense_lu_factor_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} dense_lu_factor_config_t;

typedef struct dense_lu_factor_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    dense_lu_factor_config_t config;
} dense_lu_factor_state_t;

#endif /* DENSE_LU_FACTOR_TYPES_H */
