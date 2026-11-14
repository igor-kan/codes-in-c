/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool shannon_entropy_calc_is_finite_val(double v) {
    return isfinite(v);
}

static inline double shannon_entropy_calc_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
