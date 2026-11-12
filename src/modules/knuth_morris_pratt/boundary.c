/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool knuth_morris_pratt_is_finite(double v) {
    return isfinite(v);
}

static inline double knuth_morris_pratt_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
