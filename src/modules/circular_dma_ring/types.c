/**
 * @file types.c
 * @brief Core types and configuration for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#ifndef CIRCULAR_DMA_RING_TYPES_H
#define CIRCULAR_DMA_RING_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CIRCULAR_DMA_RING_ALIGNMENT 64
#define CIRCULAR_DMA_RING_CAPACITY 2048

typedef struct circular_dma_ring_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} circular_dma_ring_config_t;

typedef struct circular_dma_ring_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    circular_dma_ring_config_t config;
} circular_dma_ring_state_t;

#endif /* CIRCULAR_DMA_RING_TYPES_H */
