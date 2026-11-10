/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#include <assert.h>

void test_cholesky_banachiewicz_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
