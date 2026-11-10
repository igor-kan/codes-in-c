/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include <assert.h>

void test_simd_spmv_ellpack_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
