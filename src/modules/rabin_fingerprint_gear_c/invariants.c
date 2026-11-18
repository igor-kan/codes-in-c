#include "interface.h"

rabin_fingerprint_gear_c_err_t rabin_fingerprint_gear_c_verify_guard(bool cond) {
    if (!cond) {
        return RABIN_FINGERPRINT_GEAR_C_ERR_INVARIANT;
    }
    return RABIN_FINGERPRINT_GEAR_C_OK;
}
