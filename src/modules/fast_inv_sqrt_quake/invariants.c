/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include <assert.h>
#include <math.h>

static inline void fast_inv_sqrt_quake_assert_invariants(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
