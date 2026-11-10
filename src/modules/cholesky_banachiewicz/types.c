/**
 * @file types.c
 * @brief Core types and configuration for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#ifndef CHOLESKY_BANACHIEWICZ_TYPES_H
#define CHOLESKY_BANACHIEWICZ_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CHOLESKY_BANACHIEWICZ_ALIGNMENT 64
#define CHOLESKY_BANACHIEWICZ_CAPACITY 4096

typedef struct cholesky_banachiewicz_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} cholesky_banachiewicz_config_t;

typedef struct cholesky_banachiewicz_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    cholesky_banachiewicz_config_t config;
} cholesky_banachiewicz_state_t;

#endif /* CHOLESKY_BANACHIEWICZ_TYPES_H */
