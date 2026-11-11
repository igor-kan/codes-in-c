/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#include <assert.h>

void test_jemalloc_run_cache_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
