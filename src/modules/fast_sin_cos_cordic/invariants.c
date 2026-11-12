/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include <assert.h>
#include <math.h>

static inline void fast_sin_cos_cordic_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
