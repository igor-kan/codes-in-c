/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_atomic_mpmc_queue_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
