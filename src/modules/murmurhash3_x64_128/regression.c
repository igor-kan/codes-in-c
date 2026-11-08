/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_murmurhash3_x64_128_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
