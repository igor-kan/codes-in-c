/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format
 */

#include <assert.h>
#include <math.h>

static inline void spmv_coo_format_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
