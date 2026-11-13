/**
 * @file concurrency.c
 * @brief Thread-safe reentrancy and atomic state primitives for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct hash_fnv1a_64_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} hash_fnv1a_64_reentrant_lock_t;

static inline void hash_fnv1a_64_seq_advance(hash_fnv1a_64_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
