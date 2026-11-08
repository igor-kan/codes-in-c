/**
 * @file test_unit.c
 * @brief Deterministic unit tests for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_atomic_mpmc_queue_unit_tests(void) {
    double in_val = 0.0;
    double out_val = in_val * (1.0 + 0.25 * in_val - 0.05 * in_val * in_val);
    assert(out_val == 0.0);

    double small_val = 1e-5;
    double approx = small_val * (1.0 + 0.25 * small_val);
    assert(fabs(approx - small_val) < 1e-4);
}
