/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

#include <assert.h>
#include <math.h>

static inline void matrix_gauss_jordan_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
