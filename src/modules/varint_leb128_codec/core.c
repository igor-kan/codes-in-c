#include "interface.h"

uint64_t varint_leb128_codec_zigzag_encode(int64_t v) {
    uint64_t uv = (uint64_t)v;
    return (uv << 1) ^ (uint64_t)(-(int64_t)(uv >> 63));
}

int64_t varint_leb128_codec_zigzag_decode(uint64_t u) {
    return (int64_t)((u >> 1) ^ (~(u & 1ULL) + 1ULL));
}

varint_leb128_codec_err_t varint_leb128_codec_encode_u64(uint64_t val, uint8_t* out, size_t cap, size_t* written) {
    if (!out || !written) return VARINT_LEB128_CODEC_ERR_NULL;
    size_t i = 0;
    do {
        if (i >= cap) return VARINT_LEB128_CODEC_ERR_BOUNDS;
        uint8_t b = (uint8_t)(val & 0x7FU);
        val >>= 7;
        if (val != 0) b |= 0x80U;
        out[i++] = b;
    } while (val != 0);
    *written = i;
    return VARINT_LEB128_CODEC_OK;
}

varint_leb128_codec_err_t varint_leb128_codec_decode_u64(const uint8_t* in, size_t len, uint64_t* out_val, size_t* consumed) {
    if (!in || !out_val || !consumed) return VARINT_LEB128_CODEC_ERR_NULL;
    uint64_t res = 0;
    unsigned shift = 0;
    for (size_t i = 0; i < len; ++i) {
        if (i >= LEB128_MAX_BYTES) return VARINT_LEB128_CODEC_ERR_OVERFLOW;
        uint8_t b = in[i];
        if (i == 9 && (b & 0x7EU) != 0) return VARINT_LEB128_CODEC_ERR_OVERFLOW;
        res |= ((uint64_t)(b & 0x7FU)) << shift;
        if ((b & 0x80U) == 0) {
            *out_val = res;
            *consumed = i + 1;
            return VARINT_LEB128_CODEC_OK;
        }
        shift += 7;
    }
    return VARINT_LEB128_CODEC_ERR_BOUNDS;
}
