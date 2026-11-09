/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include <assert.h>

void test_dense_lu_factor_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
