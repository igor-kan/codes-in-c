/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct siphash_round_c_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} siphash_round_c_sync_state_t;

static inline void siphash_round_c_sync_increment(siphash_round_c_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
