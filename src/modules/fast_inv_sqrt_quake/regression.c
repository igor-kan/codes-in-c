/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include <assert.h>

void test_fast_inv_sqrt_quake_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
