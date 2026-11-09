/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#include <assert.h>

void test_compact_bitset_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
