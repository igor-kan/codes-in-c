/**
 * @file boundary.c
 * @brief Boundary validation, clamping, and edge-case guards for Atomic CAS-Based Lock-Free Circular Queue Buffer.
 * Module: circular_queue_cas
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool circular_queue_cas_is_finite_val(double v) {
    return isfinite(v);
}

static inline double circular_queue_cas_clamp_val(double v, double min_v, double max_v) {
    if (!isfinite(v)) return 0.0;
    if (v < min_v) return min_v;
    if (v > max_v) return max_v;
    return v;
}
