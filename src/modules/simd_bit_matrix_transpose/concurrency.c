/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_bit_matrix_transpose_sync_counter {
    volatile uint64_t count;
} simd_bit_matrix_transpose_sync_counter_t;

static inline void simd_bit_matrix_transpose_sync_inc_v47(simd_bit_matrix_transpose_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
