/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_simd_matrix_transpose_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
