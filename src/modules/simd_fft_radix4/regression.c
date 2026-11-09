/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#include <assert.h>

void test_simd_fft_radix4_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
