/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#ifndef CIRCULAR_DMA_RING_INTERFACE_H
#define CIRCULAR_DMA_RING_INTERFACE_H

#include "types.c"

typedef int (*circular_dma_ring_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct circular_dma_ring_vtable {
    int (*init)(circular_dma_ring_state_t* state, const circular_dma_ring_config_t* cfg);
    int (*execute)(circular_dma_ring_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(circular_dma_ring_state_t* state);
} circular_dma_ring_vtable_t;

#endif /* CIRCULAR_DMA_RING_INTERFACE_H */
