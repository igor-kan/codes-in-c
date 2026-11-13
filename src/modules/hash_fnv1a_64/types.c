/**
 * @file types.c
 * @brief Domain types, memory layouts, and configurations for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64 | Algorithm Family: hashing
 */

#ifndef HASH_FNV1A_64_TYPES_H
#define HASH_FNV1A_64_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define HASH_FNV1A_64_ALIGNMENT 64
#define HASH_FNV1A_64_CAPACITY 2048

typedef struct hash_fnv1a_64_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} hash_fnv1a_64_config_t;

typedef struct hash_fnv1a_64_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    hash_fnv1a_64_config_t config;
} hash_fnv1a_64_state_t;

#endif /* HASH_FNV1A_64_TYPES_H */
