#include "interface.h"

cobs_framing_codec_err_t cobs_encode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return COBS_FRAMING_CODEC_ERR_NULL;
    if (dst_cap < cobs_max_encoded_size(len)) return COBS_FRAMING_CODEC_ERR_BOUNDS;
    size_t read_idx = 0, write_idx = 1, code_idx = 0;
    uint8_t code = 1;
    while (read_idx < len) {
        if (src[read_idx] == 0) {
            dst[code_idx] = code;
            code = 1;
            code_idx = write_idx++;
            read_idx++;
        } else {
            dst[write_idx++] = src[read_idx++];
            code++;
            if (code == 0xFFU) {
                dst[code_idx] = code;
                code = 1;
                code_idx = write_idx++;
            }
        }
    }
    dst[code_idx] = code;
    *out_len = write_idx;
    return COBS_FRAMING_CODEC_OK;
}

cobs_framing_codec_err_t cobs_decode(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    if (!dst || !out_len || (len > 0 && !src)) return COBS_FRAMING_CODEC_ERR_NULL;
    if (len == 0) { *out_len = 0; return COBS_FRAMING_CODEC_OK; }
    size_t read_idx = 0, write_idx = 0;
    while (read_idx < len) {
        uint8_t code = src[read_idx];
        if (code == 0) return COBS_FRAMING_CODEC_ERR_INVALID;
        read_idx++;
        for (uint8_t i = 1; i < code; ++i) {
            if (read_idx >= len) return COBS_FRAMING_CODEC_ERR_INVALID;
            if (src[read_idx] == 0) return COBS_FRAMING_CODEC_ERR_INVALID;
            if (write_idx >= dst_cap) return COBS_FRAMING_CODEC_ERR_BOUNDS;
            dst[write_idx++] = src[read_idx++];
        }
        if (code < 0xFFU && read_idx < len) {
            if (write_idx >= dst_cap) return COBS_FRAMING_CODEC_ERR_BOUNDS;
            dst[write_idx++] = 0;
        }
    }
    *out_len = write_idx;
    return COBS_FRAMING_CODEC_OK;
}
