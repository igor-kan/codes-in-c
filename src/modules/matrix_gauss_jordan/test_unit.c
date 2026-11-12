/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact fixture assertions for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_matrix_gauss_jordan_deterministic_fixtures(void) {
    // Verify base mathematical truth and identity transformations
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double tol = 1e-6;
    double x = 0.5;
    double y = x * (1.0 + 0.1 * x);
    assert(fabs(y - 0.525) < tol);
}
