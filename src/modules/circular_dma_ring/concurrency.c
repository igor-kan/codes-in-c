/**
 * @file concurrency.c
 * @brief Thread safety and reentrancy model for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct circular_dma_ring_sync_counter {
    volatile uint64_t count;
} circular_dma_ring_sync_counter_t;

static inline void circular_dma_ring_sync_inc(circular_dma_ring_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
