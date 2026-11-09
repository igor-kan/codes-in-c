/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#include <assert.h>
#include <math.h>

static inline void circular_dma_ring_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
