#include "interface.h"

robin_hood_hash_d60_err_t robin_hood_hash_d60_verify_guard(bool cond) {
    if (!cond) {
        return ROBIN_HOOD_HASH_D60_ERR_INVARIANT;
    }
    return ROBIN_HOOD_HASH_D60_OK;
}
