/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool cholesky_banachiewicz_is_valid_float(double x) {
    return isfinite(x);
}

static inline double cholesky_banachiewicz_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
