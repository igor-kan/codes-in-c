#include "interface.h"

consistent_hash_ring_c11_err_t consistent_hash_ring_c11_verify_guard(bool cond) {
    if (!cond) {
        return CONSISTENT_HASH_RING_C11_ERR_INVARIANT;
    }
    return CONSISTENT_HASH_RING_C11_OK;
}
