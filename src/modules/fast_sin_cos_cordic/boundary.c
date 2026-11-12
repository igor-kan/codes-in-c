/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool fast_sin_cos_cordic_is_finite(double v) {
    return isfinite(v);
}

static inline double fast_sin_cos_cordic_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
