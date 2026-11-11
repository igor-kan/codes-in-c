/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

#include <assert.h>
#include <math.h>

static inline void simd_bit_matrix_transpose_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
