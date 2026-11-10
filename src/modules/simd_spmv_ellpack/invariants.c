/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

#include <assert.h>
#include <math.h>

static inline void simd_spmv_ellpack_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
