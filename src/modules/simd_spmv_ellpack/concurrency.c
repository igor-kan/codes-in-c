/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_spmv_ellpack_sync_counter {
    volatile uint64_t count;
} simd_spmv_ellpack_sync_counter_t;

static inline void simd_spmv_ellpack_sync_inc(simd_spmv_ellpack_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
