/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool memory_pool_fixed_is_valid_float(double x) {
    return isfinite(x);
}

static inline double memory_pool_fixed_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
