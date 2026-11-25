#include "interface.h"

ring_spsc_lockfree_d60_err_t ring_spsc_lockfree_d60_verify_guard(bool cond) {
    if (!cond) {
        return RING_SPSC_LOCKFREE_D60_ERR_INVARIANT;
    }
    return RING_SPSC_LOCKFREE_D60_OK;
}
