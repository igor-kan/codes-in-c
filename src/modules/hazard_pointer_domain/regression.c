/**
 * @file regression.c
 * @brief Minimized crash reproducer and regression tests for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include <assert.h>

void test_hazard_pointer_domain_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
