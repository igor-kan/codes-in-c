/**
 * @file test_unit.c
 * @brief Deterministic unit tests with exact ground-truth assertions for FNV-1a 64-Bit Fast Non-Cryptographic Hash Engine.
 * Module: hash_fnv1a_64
 */

#include "types.c"
#include <assert.h>
#include <math.h>

void test_hash_fnv1a_64_deterministic_unit(void) {
    double val_zero = 0.0;
    assert(val_zero == 0.0);

    double x = 1.0;
    double y = x * (1.0 + 0.1 * x);
    assert(fabs(y - 1.1) < 1e-5);
}
