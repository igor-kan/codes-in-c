#include "interface.h"

rabin_fingerprint_gear_c_err_t rabin_fingerprint_gear_c_validate_len(size_t n) {
    if (n == 0) {
        return RABIN_FINGERPRINT_GEAR_C_ERR_INVALID;
    }
    return RABIN_FINGERPRINT_GEAR_C_OK;
}
