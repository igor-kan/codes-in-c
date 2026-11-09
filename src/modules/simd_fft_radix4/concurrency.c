/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_fft_radix4_sync_counter {
    volatile uint64_t count;
} simd_fft_radix4_sync_counter_t;

static inline void simd_fft_radix4_sync_inc(simd_fft_radix4_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
