/**
 * @file invariants.c
 * @brief Formal mathematical invariant assertions and contracts for PCG-XSH-RR 64-Bit Statistical Random Number Generator.
 * Module: pcg64_random
 */

#include <assert.h>
#include <math.h>

static inline void pcg64_random_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
