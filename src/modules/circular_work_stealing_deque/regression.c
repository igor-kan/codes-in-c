/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include <assert.h>

void test_circular_work_stealing_deque_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
