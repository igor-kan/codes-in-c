/**
 * @file boundary.c
 * @brief Boundary validation and exceptional input guarding for Harris Lock-Free Ordered Linked List with Marked Pointers.
 * Module: lockfree_ordered_list
 */

#include "types.c"
#include <math.h>
#include <stdbool.h>

static inline bool lockfree_ordered_list_is_valid_float(double x) {
    return isfinite(x);
}

static inline double lockfree_ordered_list_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
