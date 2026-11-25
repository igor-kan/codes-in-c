#include "interface.h"

robin_hood_hash_d60_err_t robin_hood_hash_d60_validate_len(size_t n) {
    if (n == 0) {
        return ROBIN_HOOD_HASH_D60_ERR_INVALID;
    }
    return ROBIN_HOOD_HASH_D60_OK;
}
