/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Robin Hood Open Addressing Cache-Friendly Hash Table.
 * Module: hash_map_robin_hood
 */

#ifndef BOUNDARY_HASH_MAP_ROBIN_HOOD_H
#define BOUNDARY_HASH_MAP_ROBIN_HOOD_H

#include <math.h>
#include <stdbool.h>

static inline bool hash_map_robin_hood_is_finite_input(double x) {
    return isfinite(x);
}

static inline double hash_map_robin_hood_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_HASH_MAP_ROBIN_HOOD_H */
