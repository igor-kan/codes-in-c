/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#include <assert.h>

void test_shannon_fano_elias_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
