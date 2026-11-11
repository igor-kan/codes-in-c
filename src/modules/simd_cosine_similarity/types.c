/**
 * @file types.c
 * @brief Core types and configuration for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#ifndef SIMD_COSINE_SIMILARITY_TYPES_H
#define SIMD_COSINE_SIMILARITY_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_COSINE_SIMILARITY_ALIGNMENT 64
#define SIMD_COSINE_SIMILARITY_DEFAULT_SZ 8192

typedef struct simd_cosine_similarity_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_cosine_similarity_config_t;

typedef struct simd_cosine_similarity_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_cosine_similarity_config_t config;
} simd_cosine_similarity_state_t;

#endif /* SIMD_COSINE_SIMILARITY_TYPES_H */
