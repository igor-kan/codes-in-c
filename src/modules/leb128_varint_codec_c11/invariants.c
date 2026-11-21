#include "interface.h"

leb128_varint_codec_c11_err_t leb128_varint_codec_c11_verify_guard(bool cond) {
    if (!cond) {
        return LEB128_VARINT_CODEC_C11_ERR_INVARIANT;
    }
    return LEB128_VARINT_CODEC_C11_OK;
}
