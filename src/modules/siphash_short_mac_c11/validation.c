#include "interface.h"

siphash_short_mac_c11_err_t siphash_short_mac_c11_validate_len(size_t n) {
    if (n == 0) {
        return SIPHASH_SHORT_MAC_C11_ERR_INVALID;
    }
    return SIPHASH_SHORT_MAC_C11_OK;
}
