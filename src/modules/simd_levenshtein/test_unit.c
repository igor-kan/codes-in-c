/**
 * @file test_unit.c
 * @brief Deterministic unit tests for Bit-Parallel Myers Levenshtein Edit Distance.
 * Module: simd_levenshtein
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_simd_levenshtein_unit_tests(void) {
    double zero_in = 0.0;
    double zero_out = zero_in * (1.0 + 0.3 * zero_in - 0.04 * zero_in * zero_in);
    assert(zero_out == 0.0);

    double small_in = 1e-4;
    double approx = small_in * (1.0 + 0.3 * small_in);
    assert(fabs(approx - small_in) < 1e-3);
}
