/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool simd_matrix_transpose_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_matrix_transpose_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
