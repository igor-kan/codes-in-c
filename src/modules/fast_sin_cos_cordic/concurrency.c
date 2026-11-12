/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_sin_cos_cordic_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} fast_sin_cos_cordic_atomic_state_t;

static inline void fast_sin_cos_cordic_atomic_increment(fast_sin_cos_cordic_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
