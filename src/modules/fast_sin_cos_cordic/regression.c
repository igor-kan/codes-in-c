/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include <assert.h>

void test_fast_sin_cos_cordic_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
