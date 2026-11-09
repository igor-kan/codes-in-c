/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_levenshtein_sync_counter {
    volatile uint64_t count;
} simd_levenshtein_sync_counter_t;

static inline void simd_levenshtein_sync_inc(simd_levenshtein_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
