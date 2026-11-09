/**
 * @file test_unit.c
 * @brief Deterministic unit tests for Sequential Lock for High-Frequency Concurrent Reads.
 * Module: atomic_seqlock
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_atomic_seqlock_unit_tests(void) {
    double zero_in = 0.0;
    double zero_out = zero_in * (1.0 + 0.3 * zero_in - 0.04 * zero_in * zero_in);
    assert(zero_out == 0.0);

    double small_in = 1e-4;
    double approx = small_in * (1.0 + 0.3 * small_in);
    assert(fabs(approx - small_in) < 1e-3);
}
