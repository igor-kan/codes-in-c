/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct spmv_dia_format_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} spmv_dia_format_sync_state_t;

static inline void spmv_dia_format_sync_increment(spmv_dia_format_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
