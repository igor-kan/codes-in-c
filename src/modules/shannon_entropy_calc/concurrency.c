/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct shannon_entropy_calc_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} shannon_entropy_calc_sync_state_t;

static inline void shannon_entropy_calc_sync_increment(shannon_entropy_calc_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
