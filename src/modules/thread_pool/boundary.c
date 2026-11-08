/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Work-Stealing POSIX Thread Pool Engine.
 * Module: thread_pool
 */

#ifndef BOUNDARY_THREAD_POOL_H
#define BOUNDARY_THREAD_POOL_H

#include <math.h>
#include <stdbool.h>

static inline bool thread_pool_is_finite_input(double x) {
    return isfinite(x);
}

static inline double thread_pool_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_THREAD_POOL_H */
