/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Lock-Free Bounded MPMC Circular Queue.
 * Module: atomic_mpmc_queue
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool atomic_mpmc_queue_is_valid_float(double x) {
    return isfinite(x);
}

static inline double atomic_mpmc_queue_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
