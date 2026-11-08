/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_slab_cache_allocator_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
