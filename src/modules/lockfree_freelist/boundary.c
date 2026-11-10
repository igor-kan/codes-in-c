/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool lockfree_freelist_is_valid_float(double x) {
    return isfinite(x);
}

static inline double lockfree_freelist_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
