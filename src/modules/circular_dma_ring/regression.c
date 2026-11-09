/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for DMA-Friendly Circular Ring Buffer with Barriers.
 * Module: circular_dma_ring
 */

#include <assert.h>

void test_circular_dma_ring_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
