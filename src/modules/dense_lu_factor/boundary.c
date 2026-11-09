/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool dense_lu_factor_is_valid_float(double x) {
    return isfinite(x);
}

static inline double dense_lu_factor_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
