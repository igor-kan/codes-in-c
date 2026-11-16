#include "interface.h"

size_t cobs_max_encoded_size(size_t src_len) {
    if (src_len == 0) return 1;
    return src_len + (src_len / 254U) + 2U;
}

cobs_framing_codec_err_t cobs_validate_buf(const uint8_t* src, size_t len, const uint8_t* dst, size_t cap) {
    if (!dst || (len > 0 && !src)) return COBS_FRAMING_CODEC_ERR_NULL;
    if (cap < cobs_max_encoded_size(len)) return COBS_FRAMING_CODEC_ERR_BOUNDS;
    return COBS_FRAMING_CODEC_OK;
}
