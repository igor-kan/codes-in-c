/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct murmurhash3_x64_128_atomic_counter {
    volatile uint64_t value;
} murmurhash3_x64_128_atomic_counter_t;

static inline void murmurhash3_x64_128_counter_inc(murmurhash3_x64_128_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
