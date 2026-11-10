/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Hazard Pointer Domain Manager for Lock-Free Memory.
 * Module: hazard_pointer_domain
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool hazard_pointer_domain_is_valid_float(double x) {
    return isfinite(x);
}

static inline double hazard_pointer_domain_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
