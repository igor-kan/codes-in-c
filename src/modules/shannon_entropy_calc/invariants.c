/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include <assert.h>
#include <math.h>

static inline void shannon_entropy_calc_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0 || fabs(out_val) < 1e-12);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
