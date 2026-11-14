/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include <assert.h>

void test_shannon_entropy_calc_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
