/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct quicksort_median_three_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} quicksort_median_three_reentrant_lock_t;

static inline void quicksort_median_three_seq_advance(quicksort_median_three_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
