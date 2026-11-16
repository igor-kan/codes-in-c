#include "interface.h"

kfifo_power2_ring_err_t kfifo_verify_invariants(const kfifo_t* q) {
    return kfifo_validate(q) == KFIFO_POWER2_RING_OK ? KFIFO_POWER2_RING_OK : KFIFO_POWER2_RING_ERR_INVARIANT;
}
