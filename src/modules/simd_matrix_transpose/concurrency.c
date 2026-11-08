/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_matrix_transpose_atomic_counter {
    volatile uint64_t value;
} simd_matrix_transpose_atomic_counter_t;

static inline void simd_matrix_transpose_counter_inc(simd_matrix_transpose_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
