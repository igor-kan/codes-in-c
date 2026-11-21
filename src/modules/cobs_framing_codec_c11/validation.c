#include "interface.h"

cobs_framing_codec_c11_err_t cobs_framing_codec_c11_validate_len(size_t n) {
    if (n == 0) {
        return COBS_FRAMING_CODEC_C11_ERR_INVALID;
    }
    return COBS_FRAMING_CODEC_C11_OK;
}
