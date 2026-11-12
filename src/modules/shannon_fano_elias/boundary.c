/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool shannon_fano_elias_is_finite(double v) {
    return isfinite(v);
}

static inline double shannon_fano_elias_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
