/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct dense_lu_factor_sync_counter {
    volatile uint64_t count;
} dense_lu_factor_sync_counter_t;

static inline void dense_lu_factor_sync_inc(dense_lu_factor_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
