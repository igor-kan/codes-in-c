#include "interface.h"

ring_spsc_lockfree_d60_err_t ring_spsc_lockfree_d60_validate_len(size_t n) {
    if (n == 0) {
        return RING_SPSC_LOCKFREE_D60_ERR_INVALID;
    }
    return RING_SPSC_LOCKFREE_D60_OK;
}
