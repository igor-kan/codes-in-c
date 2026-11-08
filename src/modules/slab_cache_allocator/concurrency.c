/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct slab_cache_allocator_atomic_counter {
    volatile uint64_t value;
} slab_cache_allocator_atomic_counter_t;

static inline void slab_cache_allocator_counter_inc(slab_cache_allocator_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
