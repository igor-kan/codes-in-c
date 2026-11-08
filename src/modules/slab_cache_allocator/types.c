/**
 * @file types.c
 * @brief Core types and configuration for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#ifndef SLAB_CACHE_ALLOCATOR_TYPES_H
#define SLAB_CACHE_ALLOCATOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SLAB_CACHE_ALLOCATOR_ALIGNMENT 64
#define SLAB_CACHE_ALLOCATOR_DEFAULT_CAPACITY 1024

typedef struct slab_cache_allocator_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} slab_cache_allocator_config_t;

typedef struct slab_cache_allocator_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    slab_cache_allocator_config_t config;
} slab_cache_allocator_state_t;

#endif /* SLAB_CACHE_ALLOCATOR_TYPES_H */
