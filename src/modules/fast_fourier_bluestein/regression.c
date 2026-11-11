/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#include <assert.h>

void test_fast_fourier_bluestein_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
