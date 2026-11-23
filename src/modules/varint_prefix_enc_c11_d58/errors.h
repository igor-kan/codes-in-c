#ifndef VARINT_PREFIX_ENC_C11_D58_ERRORS_H
#define VARINT_PREFIX_ENC_C11_D58_ERRORS_H

typedef enum varint_prefix_enc_c11_d58_err {
    VARINT_PREFIX_ENC_C11_D58_OK = 0,
    VARINT_PREFIX_ENC_C11_D58_ERR_NULL = -1,
    VARINT_PREFIX_ENC_C11_D58_ERR_BOUNDS = -2,
    VARINT_PREFIX_ENC_C11_D58_ERR_INVALID = -3,
    VARINT_PREFIX_ENC_C11_D58_ERR_OVERFLOW = -4,
    VARINT_PREFIX_ENC_C11_D58_ERR_INVARIANT = -5
} varint_prefix_enc_c11_d58_err_t;



static inline const char* varint_prefix_enc_c11_d58_err_str(varint_prefix_enc_c11_d58_err_t err) {
    switch (err) {
        case VARINT_PREFIX_ENC_C11_D58_OK: return "ok";
        case VARINT_PREFIX_ENC_C11_D58_ERR_NULL: return "null pointer supplied";
        case VARINT_PREFIX_ENC_C11_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case VARINT_PREFIX_ENC_C11_D58_ERR_INVALID: return "domain precondition violated";
        case VARINT_PREFIX_ENC_C11_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case VARINT_PREFIX_ENC_C11_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* VARINT_PREFIX_ENC_C11_D58_ERRORS_H */
