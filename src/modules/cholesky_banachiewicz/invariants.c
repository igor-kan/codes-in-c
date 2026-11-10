/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Row-by-Row Cholesky-Banachiewicz Matrix Factorization.
 * Module: cholesky_banachiewicz
 */

#include <assert.h>
#include <math.h>

static inline void cholesky_banachiewicz_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
