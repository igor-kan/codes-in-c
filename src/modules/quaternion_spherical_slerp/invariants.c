/**
 * @file invariants.c
 * @brief Mathematical invariants and contract assertions for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_spherical_slerp
 */

#include <assert.h>
#include <math.h>

static inline void quaternion_spherical_slerp_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
