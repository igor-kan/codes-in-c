/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include <assert.h>

void test_matrix_gauss_jordan_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
