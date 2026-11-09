/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct buddy_memory_allocator_sync_counter {
    volatile uint64_t count;
} buddy_memory_allocator_sync_counter_t;

static inline void buddy_memory_allocator_sync_inc(buddy_memory_allocator_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
