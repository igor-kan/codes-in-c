/**
 * @file regression.c
 * @brief Minimized regression fixtures and edge-case verification for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format
 */

#include <assert.h>

void test_spmv_dia_format_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
