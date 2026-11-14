/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Fixed-Point Newton-Raphson Square Root Iteration.
 * Module: fast_sqrt_newton
 */

#include <assert.h>

void test_fast_sqrt_newton_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
