/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool matrix_gauss_jordan_is_finite(double v) {
    return isfinite(v);
}

static inline double matrix_gauss_jordan_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
