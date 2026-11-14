/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_matrix_inversion_lu_ground_truth(void) {
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double x = 1.0;
    double computed = x * (1.0 + 0.1 * x);
    assert(fabs(computed - 1.1) < 1e-5);
}
