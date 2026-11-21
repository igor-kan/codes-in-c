#include "interface.h"

siphash_short_mac_c11_err_t siphash_short_mac_c11_verify_guard(bool cond) {
    if (!cond) {
        return SIPHASH_SHORT_MAC_C11_ERR_INVARIANT;
    }
    return SIPHASH_SHORT_MAC_C11_OK;
}
