/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_fourier_split_radix_sync_counter {
    volatile uint64_t count;
} fast_fourier_split_radix_sync_counter_t;

static inline void fast_fourier_split_radix_sync_inc(fast_fourier_split_radix_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
