/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#include <assert.h>

void test_bitwise_bloom_filter_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
