#include "interface.h"

ring_spsc_bytes_c11_d59_err_t ring_spsc_bytes_c11_d59_validate_len(size_t n) {
    if (n == 0) {
        return RING_SPSC_BYTES_C11_D59_ERR_INVALID;
    }
    return RING_SPSC_BYTES_C11_D59_OK;
}
