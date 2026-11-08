/**
 * @file types.c
 * @brief Core types and configuration for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#ifndef MURMURHASH3_X64_128_TYPES_H
#define MURMURHASH3_X64_128_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MURMURHASH3_X64_128_ALIGNMENT 64
#define MURMURHASH3_X64_128_DEFAULT_CAPACITY 1024

typedef struct murmurhash3_x64_128_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} murmurhash3_x64_128_config_t;

typedef struct murmurhash3_x64_128_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    murmurhash3_x64_128_config_t config;
} murmurhash3_x64_128_state_t;

#endif /* MURMURHASH3_X64_128_TYPES_H */
