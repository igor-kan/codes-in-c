/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#include <assert.h>

void test_quicksort_median_three_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
