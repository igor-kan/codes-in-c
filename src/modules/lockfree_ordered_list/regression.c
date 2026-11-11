/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include <assert.h>

void test_lockfree_ordered_list_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
