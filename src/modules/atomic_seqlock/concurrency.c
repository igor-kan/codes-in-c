/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct atomic_seqlock_sync_counter {
    volatile uint64_t count;
} atomic_seqlock_sync_counter_t;

static inline void atomic_seqlock_sync_inc(atomic_seqlock_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
