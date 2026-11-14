/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct matrix_inversion_lu_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} matrix_inversion_lu_sync_state_t;

static inline void matrix_inversion_lu_sync_increment(matrix_inversion_lu_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
