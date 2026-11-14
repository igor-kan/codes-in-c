/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c | Algorithm Family: hashing
 */

#ifndef SIPHASH_ROUND_C_TYPES_H
#define SIPHASH_ROUND_C_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIPHASH_ROUND_C_ALIGNMENT 64
#define SIPHASH_ROUND_C_CAPACITY 4096

typedef struct siphash_round_c_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} siphash_round_c_config_t;

typedef struct siphash_round_c_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    siphash_round_c_config_t config;
} siphash_round_c_state_t;

#endif /* SIPHASH_ROUND_C_TYPES_H */
