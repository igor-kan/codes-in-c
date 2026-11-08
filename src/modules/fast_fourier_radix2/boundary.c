/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Cooley-Tukey In-Place Radix-2 FFT Engine.
 * Module: fast_fourier_radix2
 */

#ifndef BOUNDARY_FAST_FOURIER_RADIX2_H
#define BOUNDARY_FAST_FOURIER_RADIX2_H

#include <math.h>
#include <stdbool.h>

static inline bool fast_fourier_radix2_is_finite_input(double x) {
    return isfinite(x);
}

static inline double fast_fourier_radix2_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_FAST_FOURIER_RADIX2_H */
