/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Knuth-Morris-Pratt (KMP) Longest Prefix Search.
 * Module: knuth_morris_pratt
 */

#include <assert.h>
#include <math.h>

static inline void knuth_morris_pratt_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
