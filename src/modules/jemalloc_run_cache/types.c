/**
 * @file types.c
 * @brief Core types and configuration for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#ifndef JEMALLOC_RUN_CACHE_TYPES_H
#define JEMALLOC_RUN_CACHE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define JEMALLOC_RUN_CACHE_ALIGNMENT 64
#define JEMALLOC_RUN_CACHE_DEFAULT_SZ 8192

typedef struct jemalloc_run_cache_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} jemalloc_run_cache_config_t;

typedef struct jemalloc_run_cache_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    jemalloc_run_cache_config_t config;
} jemalloc_run_cache_state_t;

#endif /* JEMALLOC_RUN_CACHE_TYPES_H */
