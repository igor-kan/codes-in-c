#include "interface.h"

consistent_hash_ring_c11_err_t consistent_hash_ring_c11_validate_len(size_t n) {
    if (n == 0) {
        return CONSISTENT_HASH_RING_C11_ERR_INVALID;
    }
    return CONSISTENT_HASH_RING_C11_OK;
}
