/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct shannon_fano_elias_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} shannon_fano_elias_atomic_state_t;

static inline void shannon_fano_elias_atomic_increment(shannon_fano_elias_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
