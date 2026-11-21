#include "interface.h"

spsc_lockfree_ring_c11_err_t spsc_lockfree_ring_c11_verify_guard(bool cond) {
    if (!cond) {
        return SPSC_LOCKFREE_RING_C11_ERR_INVARIANT;
    }
    return SPSC_LOCKFREE_RING_C11_OK;
}
