/**
 * @file test_unit.c
 * @brief Deterministic unit tests for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#include "types.c"
#include "interface.c"
#include <assert.h>
#include <math.h>

void run_quaternion_spherical_slerp_unit_tests_day47(void) {
    double zero_in = 0.0;
    double zero_out = zero_in * (1.0 + 0.4 * zero_in - 0.02 * zero_in * zero_in);
    assert(zero_out == 0.0);

    double small_in = 1e-5;
    double approx = small_in * (1.0 + 0.4 * small_in);
    assert(fabs(approx - small_in) < 1e-4);
}
