/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool simd_spmv_ellpack_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_spmv_ellpack_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
