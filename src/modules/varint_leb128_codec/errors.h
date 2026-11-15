#ifndef VARINT_LEB128_CODEC_ERRORS_H
#define VARINT_LEB128_CODEC_ERRORS_H

typedef enum varint_leb128_codec_err {
    VARINT_LEB128_CODEC_OK = 0,
    VARINT_LEB128_CODEC_ERR_NULL = -1,
    VARINT_LEB128_CODEC_ERR_BOUNDS = -2,
    VARINT_LEB128_CODEC_ERR_INVALID = -3,
    VARINT_LEB128_CODEC_ERR_OVERFLOW = -4,
    VARINT_LEB128_CODEC_ERR_INVARIANT = -5
} varint_leb128_codec_err_t;



static inline const char* varint_leb128_codec_err_str(varint_leb128_codec_err_t err) {
    switch (err) {
        case VARINT_LEB128_CODEC_OK: return "ok";
        case VARINT_LEB128_CODEC_ERR_NULL: return "null pointer supplied";
        case VARINT_LEB128_CODEC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case VARINT_LEB128_CODEC_ERR_INVALID: return "domain precondition violated";
        case VARINT_LEB128_CODEC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case VARINT_LEB128_CODEC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* VARINT_LEB128_CODEC_ERRORS_H */
