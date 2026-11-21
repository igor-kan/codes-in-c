#include "interface.h"

cobs_framing_codec_c11_err_t cobs_framing_codec_c11_verify_guard(bool cond) {
    if (!cond) {
        return COBS_FRAMING_CODEC_C11_ERR_INVARIANT;
    }
    return COBS_FRAMING_CODEC_C11_OK;
}
