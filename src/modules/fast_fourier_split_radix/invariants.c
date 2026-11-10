/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Split-Radix FFT Algorithm Minimizing Arithmetic Ops.
 * Module: fast_fourier_split_radix
 */

#include <assert.h>
#include <math.h>

static inline void fast_fourier_split_radix_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
