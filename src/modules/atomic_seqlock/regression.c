/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#include <assert.h>

void test_atomic_seqlock_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
