/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Optimized 128-Bit MurmurHash3 Hashing Engine.
 * Module: murmurhash3_x64_128
 */

#include <assert.h>
#include <math.h>

static inline void murmurhash3_x64_128_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
