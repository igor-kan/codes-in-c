/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool fast_fourier_bluestein_is_valid_float(double x) {
    return isfinite(x);
}

static inline double fast_fourier_bluestein_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
