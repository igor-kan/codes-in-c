/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for AVX2 Radix-4 Fast Fourier Transform Kernel.
 * Module: simd_fft_radix4
 */

#include <assert.h>
#include <math.h>

static inline void simd_fft_radix4_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
