/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct knuth_morris_pratt_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} knuth_morris_pratt_atomic_state_t;

static inline void knuth_morris_pratt_atomic_increment(knuth_morris_pratt_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
