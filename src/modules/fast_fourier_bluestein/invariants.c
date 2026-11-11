/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Bluestein Chirp-Z Algorithm for Arbitrary-Size FFT.
 * Module: fast_fourier_bluestein
 */

#include <assert.h>
#include <math.h>

static inline void fast_fourier_bluestein_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
