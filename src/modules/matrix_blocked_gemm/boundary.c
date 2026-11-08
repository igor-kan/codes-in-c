/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Cache-Blocked Matrix GEMM with Loop Tiling.
 * Module: matrix_blocked_gemm
 */

#ifndef BOUNDARY_MATRIX_BLOCKED_GEMM_H
#define BOUNDARY_MATRIX_BLOCKED_GEMM_H

#include <math.h>
#include <stdbool.h>

static inline bool matrix_blocked_gemm_is_finite_input(double x) {
    return isfinite(x);
}

static inline double matrix_blocked_gemm_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_MATRIX_BLOCKED_GEMM_H */
