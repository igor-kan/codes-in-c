/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool quicksort_median_three_check_finite(double v) {
    return isfinite(v);
}

static inline double quicksort_median_three_bound_clamp(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
