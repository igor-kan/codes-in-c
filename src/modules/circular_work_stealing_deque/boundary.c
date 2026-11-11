/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Circular Work-Stealing Deque with Memory Fencing.
 * Module: circular_work_stealing_deque
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool circular_work_stealing_deque_is_valid_float(double x) {
    return isfinite(x);
}

static inline double circular_work_stealing_deque_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
