/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct memory_pool_fixed_sync_counter {
    volatile uint64_t count;
} memory_pool_fixed_sync_counter_t;

static inline void memory_pool_fixed_sync_inc_v47(memory_pool_fixed_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
