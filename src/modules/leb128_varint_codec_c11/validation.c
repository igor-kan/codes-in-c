#include "interface.h"

leb128_varint_codec_c11_err_t leb128_varint_codec_c11_validate_len(size_t n) {
    if (n == 0) {
        return LEB128_VARINT_CODEC_C11_ERR_INVALID;
    }
    return LEB128_VARINT_CODEC_C11_OK;
}
