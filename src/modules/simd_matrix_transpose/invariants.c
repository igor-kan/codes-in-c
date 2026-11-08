/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

#include <assert.h>
#include <math.h>

static inline void simd_matrix_transpose_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
