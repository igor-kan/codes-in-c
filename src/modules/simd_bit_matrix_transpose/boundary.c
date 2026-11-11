/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool simd_bit_matrix_transpose_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_bit_matrix_transpose_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
