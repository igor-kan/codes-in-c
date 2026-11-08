/**
 * Boundary condition checking and IEEE-754 edge-case handlers for 64-Byte Aligned Bump Arena Memory Allocator.
 * Module: arena_allocator
 */

#ifndef BOUNDARY_ARENA_ALLOCATOR_H
#define BOUNDARY_ARENA_ALLOCATOR_H

#include <math.h>
#include <stdbool.h>

static inline bool arena_allocator_is_finite_input(double x) {
    return isfinite(x);
}

static inline double arena_allocator_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_ARENA_ALLOCATOR_H */
