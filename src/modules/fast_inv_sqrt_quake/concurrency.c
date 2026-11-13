/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct fast_inv_sqrt_quake_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} fast_inv_sqrt_quake_reentrant_lock_t;

static inline void fast_inv_sqrt_quake_seq_advance(fast_inv_sqrt_quake_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
