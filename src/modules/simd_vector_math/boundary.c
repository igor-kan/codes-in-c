/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Vectorized Float64 Dot Product and Euclidean Norm.
 * Module: simd_vector_math
 */

#ifndef BOUNDARY_SIMD_VECTOR_MATH_H
#define BOUNDARY_SIMD_VECTOR_MATH_H

#include <math.h>
#include <stdbool.h>

static inline bool simd_vector_math_is_finite_input(double x) {
    return isfinite(x);
}

static inline double simd_vector_math_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_SIMD_VECTOR_MATH_H */
