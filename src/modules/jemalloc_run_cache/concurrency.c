/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct jemalloc_run_cache_sync_counter {
    volatile uint64_t count;
} jemalloc_run_cache_sync_counter_t;

static inline void jemalloc_run_cache_sync_inc_v47(jemalloc_run_cache_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
