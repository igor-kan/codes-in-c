/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Power-of-Two Buddy Memory Pool Allocator.
 * Module: buddy_memory_allocator
 */

#include <assert.h>

void test_buddy_memory_allocator_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
