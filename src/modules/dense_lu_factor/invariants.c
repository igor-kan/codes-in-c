/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for In-Place Dense LU Factorization with Pivoting.
 * Module: dense_lu_factor
 */

#include <assert.h>
#include <math.h>

static inline void dense_lu_factor_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
