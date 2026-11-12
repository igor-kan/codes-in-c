/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias | Algorithm Family: compression
 */

#ifndef SHANNON_FANO_ELIAS_TYPES_H
#define SHANNON_FANO_ELIAS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SHANNON_FANO_ELIAS_ALIGNMENT 64
#define SHANNON_FANO_ELIAS_BASE_CAPACITY 1024

typedef struct shannon_fano_elias_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} shannon_fano_elias_config_t;

typedef struct shannon_fano_elias_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    shannon_fano_elias_config_t config;
} shannon_fano_elias_state_t;

#endif /* SHANNON_FANO_ELIAS_TYPES_H */
