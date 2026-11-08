/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Lock-Free SPSC Circular Ring Buffer.
 * Module: ring_buffer
 */

#ifndef BOUNDARY_RING_BUFFER_H
#define BOUNDARY_RING_BUFFER_H

#include <math.h>
#include <stdbool.h>

static inline bool ring_buffer_is_finite_input(double x) {
    return isfinite(x);
}

static inline double ring_buffer_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_RING_BUFFER_H */
