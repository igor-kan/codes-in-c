/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool simd_fft_radix4_is_valid_float(double x) {
    return isfinite(x);
}

static inline double simd_fft_radix4_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
