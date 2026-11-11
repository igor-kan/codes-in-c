/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_fourier_bluestein_sync_counter {
    volatile uint64_t count;
} fast_fourier_bluestein_sync_counter_t;

static inline void fast_fourier_bluestein_sync_inc_v47(fast_fourier_bluestein_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
