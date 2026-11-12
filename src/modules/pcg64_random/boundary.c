/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool pcg64_random_is_finite(double v) {
    return isfinite(v);
}

static inline double pcg64_random_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
