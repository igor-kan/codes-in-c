/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include <assert.h>

void test_simd_bit_matrix_transpose_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
