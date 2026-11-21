#include "interface.h"

spsc_lockfree_ring_c11_err_t spsc_lockfree_ring_c11_validate_len(size_t n) {
    if (n == 0) {
        return SPSC_LOCKFREE_RING_C11_ERR_INVALID;
    }
    return SPSC_LOCKFREE_RING_C11_OK;
}
