#ifndef LZSS_FLAG_CODEC_C11_D58_ERRORS_H
#define LZSS_FLAG_CODEC_C11_D58_ERRORS_H

typedef enum lzss_flag_codec_c11_d58_err {
    LZSS_FLAG_CODEC_C11_D58_OK = 0,
    LZSS_FLAG_CODEC_C11_D58_ERR_NULL = -1,
    LZSS_FLAG_CODEC_C11_D58_ERR_BOUNDS = -2,
    LZSS_FLAG_CODEC_C11_D58_ERR_INVALID = -3,
    LZSS_FLAG_CODEC_C11_D58_ERR_OVERFLOW = -4,
    LZSS_FLAG_CODEC_C11_D58_ERR_INVARIANT = -5
} lzss_flag_codec_c11_d58_err_t;



static inline const char* lzss_flag_codec_c11_d58_err_str(lzss_flag_codec_c11_d58_err_t err) {
    switch (err) {
        case LZSS_FLAG_CODEC_C11_D58_OK: return "ok";
        case LZSS_FLAG_CODEC_C11_D58_ERR_NULL: return "null pointer supplied";
        case LZSS_FLAG_CODEC_C11_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case LZSS_FLAG_CODEC_C11_D58_ERR_INVALID: return "domain precondition violated";
        case LZSS_FLAG_CODEC_C11_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case LZSS_FLAG_CODEC_C11_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* LZSS_FLAG_CODEC_C11_D58_ERRORS_H */
