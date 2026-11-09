/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Hardware-Accelerated CRC32-C Checksum Engine.
 * Module: crc32c_hardware
 */

#include <assert.h>
#include <math.h>

static inline void crc32c_hardware_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
