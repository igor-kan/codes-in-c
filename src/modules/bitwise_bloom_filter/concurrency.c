/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bitwise_bloom_filter_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} bitwise_bloom_filter_reentrant_lock_t;

static inline void bitwise_bloom_filter_seq_advance(bitwise_bloom_filter_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
