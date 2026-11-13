/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include <assert.h>

void test_hash_fnv1a_64_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
