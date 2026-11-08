/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Clenshaw Recurrence Chebyshev Series Evaluator.
 * Module: chebyshev_eval
 */

#ifndef BOUNDARY_CHEBYSHEV_EVAL_H
#define BOUNDARY_CHEBYSHEV_EVAL_H

#include <math.h>
#include <stdbool.h>

static inline bool chebyshev_eval_is_finite_input(double x) {
    return isfinite(x);
}

static inline double chebyshev_eval_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_CHEBYSHEV_EVAL_H */
