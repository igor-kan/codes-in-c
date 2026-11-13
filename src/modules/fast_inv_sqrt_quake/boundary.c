/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool fast_inv_sqrt_quake_check_finite(double v) {
    return isfinite(v);
}

static inline double fast_inv_sqrt_quake_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
