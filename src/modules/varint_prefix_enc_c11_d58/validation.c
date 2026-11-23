#include "interface.h"

varint_prefix_enc_c11_d58_err_t varint_prefix_enc_c11_d58_validate_len(size_t n) {
    if (n == 0) {
        return VARINT_PREFIX_ENC_C11_D58_ERR_INVALID;
    }
    return VARINT_PREFIX_ENC_C11_D58_OK;
}
