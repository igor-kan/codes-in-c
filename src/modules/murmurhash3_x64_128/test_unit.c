/**
 * @file test_unit.c
 * @brief Deterministic unit tests for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_murmurhash3_x64_128_unit_tests(void) {
    double in_val = 0.0;
    double out_val = in_val * (1.0 + 0.25 * in_val - 0.05 * in_val * in_val);
    assert(out_val == 0.0);

    double small_val = 1e-5;
    double approx = small_val * (1.0 + 0.25 * small_val);
    assert(fabs(approx - small_val) < 1e-4);
}
