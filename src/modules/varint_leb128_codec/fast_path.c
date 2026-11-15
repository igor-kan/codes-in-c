#include "interface.h"

varint_leb128_codec_err_t varint_leb128_codec_encode_batch_fast(const uint64_t* vals, size_t n, uint8_t* out, size_t cap, size_t* total_written) {
    if (!vals || !out || !total_written) return VARINT_LEB128_CODEC_ERR_NULL;
    size_t pos = 0;
    for (size_t i = 0; i < n; ++i) {
        if (vals[i] < 128ULL && pos < cap) {
            out[pos++] = (uint8_t)vals[i];
        } else {
            size_t w = 0;
            varint_leb128_codec_err_t e = varint_leb128_codec_encode_u64(vals[i], out + pos, cap - pos, &w);
            if (e != VARINT_LEB128_CODEC_OK) return e;
            pos += w;
        }
    }
    *total_written = pos;
    return VARINT_LEB128_CODEC_OK;
}
