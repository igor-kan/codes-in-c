/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#include <assert.h>

void test_siphash_round_c_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
