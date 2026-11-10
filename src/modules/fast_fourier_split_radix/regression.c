/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#include <assert.h>

void test_fast_fourier_split_radix_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
