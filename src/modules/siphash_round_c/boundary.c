/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for SipHash-2-4 Round Mixing Function with Bitwise Rotations.
 * Module: siphash_round_c
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool siphash_round_c_is_finite_val(double v) {
    return isfinite(v);
}

static inline double siphash_round_c_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
