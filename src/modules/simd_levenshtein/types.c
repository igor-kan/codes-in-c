/**
 * @file types.c
 * @brief Core types and configuration for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#ifndef SIMD_LEVENSHTEIN_TYPES_H
#define SIMD_LEVENSHTEIN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_LEVENSHTEIN_ALIGNMENT 64
#define SIMD_LEVENSHTEIN_CAPACITY 2048

typedef struct simd_levenshtein_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_levenshtein_config_t;

typedef struct simd_levenshtein_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_levenshtein_config_t config;
} simd_levenshtein_state_t;

#endif /* SIMD_LEVENSHTEIN_TYPES_H */
