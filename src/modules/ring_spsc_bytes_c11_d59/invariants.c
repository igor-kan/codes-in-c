#include "interface.h"

ring_spsc_bytes_c11_d59_err_t ring_spsc_bytes_c11_d59_verify_guard(bool cond) {
    if (!cond) {
        return RING_SPSC_BYTES_C11_D59_ERR_INVARIANT;
    }
    return RING_SPSC_BYTES_C11_D59_OK;
}
