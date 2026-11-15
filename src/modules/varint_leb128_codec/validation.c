#include "interface.h"

varint_leb128_codec_err_t varint_leb128_codec_validate_stream(const uint8_t* buf, size_t len) {
    if (len > 0 && !buf) return VARINT_LEB128_CODEC_ERR_NULL;
    size_t run = 0;
    for (size_t i = 0; i < len; ++i) {
        run++;
        if ((buf[i] & 0x80U) == 0) run = 0;
        else if (run >= LEB128_MAX_BYTES) return VARINT_LEB128_CODEC_ERR_OVERFLOW;
    }
    return (run == 0) ? VARINT_LEB128_CODEC_OK : VARINT_LEB128_CODEC_ERR_BOUNDS;
}
