/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_sqrt_newton_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} fast_sqrt_newton_sync_state_t;

static inline void fast_sqrt_newton_sync_increment(fast_sqrt_newton_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
