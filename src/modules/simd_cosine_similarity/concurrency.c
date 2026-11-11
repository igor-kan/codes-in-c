/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_cosine_similarity_sync_counter {
    volatile uint64_t count;
} simd_cosine_similarity_sync_counter_t;

static inline void simd_cosine_similarity_sync_inc_v47(simd_cosine_similarity_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
