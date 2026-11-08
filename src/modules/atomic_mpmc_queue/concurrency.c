/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct atomic_mpmc_queue_atomic_counter {
    volatile uint64_t value;
} atomic_mpmc_queue_atomic_counter_t;

static inline void atomic_mpmc_queue_counter_inc(atomic_mpmc_queue_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
