#include "interface.h"

varint_leb128_codec_err_t varint_leb128_codec_check_roundtrip(int64_t signed_val) {
    uint8_t buf[16];
    size_t w = 0, c = 0;
    uint64_t zz = varint_leb128_codec_zigzag_encode(signed_val);
    varint_leb128_codec_err_t e = varint_leb128_codec_encode_u64(zz, buf, 16, &w);
    if (e != VARINT_LEB128_CODEC_OK) return e;
    uint64_t dec_zz = 0;
    e = varint_leb128_codec_decode_u64(buf, w, &dec_zz, &c);
    if (e != VARINT_LEB128_CODEC_OK) return e;
    if (c != w || varint_leb128_codec_zigzag_decode(dec_zz) != signed_val) return VARINT_LEB128_CODEC_ERR_INVARIANT;
    return VARINT_LEB128_CODEC_OK;
}
