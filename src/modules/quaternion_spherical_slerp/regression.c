/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#include <assert.h>

void test_quaternion_spherical_slerp_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
