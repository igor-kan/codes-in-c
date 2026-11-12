/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for Shannon-Fano-Elias Cumulative Distribution Codec.
 * Module: shannon_fano_elias
 */

#include <assert.h>
#include <math.h>

static inline void shannon_fano_elias_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
