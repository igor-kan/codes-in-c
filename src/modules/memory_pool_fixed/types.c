/**
 * @file types.c
 * @brief Core types and configuration for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#ifndef MEMORY_POOL_FIXED_TYPES_H
#define MEMORY_POOL_FIXED_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MEMORY_POOL_FIXED_ALIGNMENT 64
#define MEMORY_POOL_FIXED_DEFAULT_SZ 8192

typedef struct memory_pool_fixed_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} memory_pool_fixed_config_t;

typedef struct memory_pool_fixed_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    memory_pool_fixed_config_t config;
} memory_pool_fixed_state_t;

#endif /* MEMORY_POOL_FIXED_TYPES_H */
