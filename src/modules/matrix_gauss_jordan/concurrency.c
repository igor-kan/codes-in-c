/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct matrix_gauss_jordan_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} matrix_gauss_jordan_atomic_state_t;

static inline void matrix_gauss_jordan_atomic_increment(matrix_gauss_jordan_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
