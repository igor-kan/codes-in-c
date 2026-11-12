/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct spmv_coo_format_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} spmv_coo_format_atomic_state_t;

static inline void spmv_coo_format_atomic_increment(spmv_coo_format_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
