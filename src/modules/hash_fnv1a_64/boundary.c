/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool hash_fnv1a_64_check_finite(double v) {
    return isfinite(v);
}

static inline double hash_fnv1a_64_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
