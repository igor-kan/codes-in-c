/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct pcg64_random_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} pcg64_random_atomic_state_t;

static inline void pcg64_random_atomic_increment(pcg64_random_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
