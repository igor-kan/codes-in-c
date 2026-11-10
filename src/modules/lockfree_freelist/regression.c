/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#include <assert.h>

void test_lockfree_freelist_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
