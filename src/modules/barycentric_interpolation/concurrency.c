/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct barycentric_interpolation_atomic_counter {
    volatile uint64_t value;
} barycentric_interpolation_atomic_counter_t;

static inline void barycentric_interpolation_counter_inc(barycentric_interpolation_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
