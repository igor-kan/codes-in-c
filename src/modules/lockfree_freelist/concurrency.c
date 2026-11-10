/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_freelist_sync_counter {
    volatile uint64_t count;
} lockfree_freelist_sync_counter_t;

static inline void lockfree_freelist_sync_inc(lockfree_freelist_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
