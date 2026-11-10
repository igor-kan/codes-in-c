/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct cholesky_banachiewicz_sync_counter {
    volatile uint64_t count;
} cholesky_banachiewicz_sync_counter_t;

static inline void cholesky_banachiewicz_sync_inc(cholesky_banachiewicz_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
