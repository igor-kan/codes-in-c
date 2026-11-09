/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct compact_bitset_sync_counter {
    volatile uint64_t count;
} compact_bitset_sync_counter_t;

static inline void compact_bitset_sync_inc(compact_bitset_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
