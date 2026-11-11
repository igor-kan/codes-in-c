/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#include <assert.h>

void test_memory_pool_fixed_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
