#include "interface.h"

varint_prefix_enc_c11_d58_err_t varint_prefix_enc_c11_d58_verify_guard(bool cond) {
    if (!cond) {
        return VARINT_PREFIX_ENC_C11_D58_ERR_INVARIANT;
    }
    return VARINT_PREFIX_ENC_C11_D58_OK;
}
