#ifndef LEB128_VARINT_CODEC_C11_ERRORS_H
#define LEB128_VARINT_CODEC_C11_ERRORS_H

typedef enum leb128_varint_codec_c11_err {
    LEB128_VARINT_CODEC_C11_OK = 0,
    LEB128_VARINT_CODEC_C11_ERR_NULL = -1,
    LEB128_VARINT_CODEC_C11_ERR_BOUNDS = -2,
    LEB128_VARINT_CODEC_C11_ERR_INVALID = -3,
    LEB128_VARINT_CODEC_C11_ERR_OVERFLOW = -4,
    LEB128_VARINT_CODEC_C11_ERR_INVARIANT = -5
} leb128_varint_codec_c11_err_t;



static inline const char* leb128_varint_codec_c11_err_str(leb128_varint_codec_c11_err_t err) {
    switch (err) {
        case LEB128_VARINT_CODEC_C11_OK: return "ok";
        case LEB128_VARINT_CODEC_C11_ERR_NULL: return "null pointer supplied";
        case LEB128_VARINT_CODEC_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case LEB128_VARINT_CODEC_C11_ERR_INVALID: return "domain precondition violated";
        case LEB128_VARINT_CODEC_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case LEB128_VARINT_CODEC_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* LEB128_VARINT_CODEC_C11_ERRORS_H */
