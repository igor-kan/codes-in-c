/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for High-Order Barycentric Rational Interpolator.
 * Module: barycentric_interpolation
 */

#include <assert.h>
#include <math.h>

static inline void barycentric_interpolation_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
