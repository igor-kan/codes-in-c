/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool bitwise_bloom_filter_check_finite(double v) {
    return isfinite(v);
}

static inline double bitwise_bloom_filter_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
