#include "interface.h"

varint_leb128_codec_err_t varint_leb128_codec_decode_batch(const uint8_t* buf, size_t len, uint64_t* vals, size_t max_n, size_t* decoded_n) {
    if (!buf || !vals || !decoded_n) return VARINT_LEB128_CODEC_ERR_NULL;
    size_t pos = 0, cnt = 0;
    while (pos < len && cnt < max_n) {
        size_t c = 0;
        varint_leb128_codec_err_t e = varint_leb128_codec_decode_u64(buf + pos, len - pos, &vals[cnt], &c);
        if (e != VARINT_LEB128_CODEC_OK) return e;
        pos += c;
        cnt++;
    }
    *decoded_n = cnt;
    return VARINT_LEB128_CODEC_OK;
}
