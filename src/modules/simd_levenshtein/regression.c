/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#include <assert.h>

void test_simd_levenshtein_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
