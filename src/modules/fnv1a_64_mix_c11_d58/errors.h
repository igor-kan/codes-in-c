#ifndef FNV1A_64_MIX_C11_D58_ERRORS_H
#define FNV1A_64_MIX_C11_D58_ERRORS_H

typedef enum fnv1a_64_mix_c11_d58_err {
    FNV1A_64_MIX_C11_D58_OK = 0,
    FNV1A_64_MIX_C11_D58_ERR_NULL = -1,
    FNV1A_64_MIX_C11_D58_ERR_BOUNDS = -2,
    FNV1A_64_MIX_C11_D58_ERR_INVALID = -3,
    FNV1A_64_MIX_C11_D58_ERR_OVERFLOW = -4,
    FNV1A_64_MIX_C11_D58_ERR_INVARIANT = -5
} fnv1a_64_mix_c11_d58_err_t;



static inline const char* fnv1a_64_mix_c11_d58_err_str(fnv1a_64_mix_c11_d58_err_t err) {
    switch (err) {
        case FNV1A_64_MIX_C11_D58_OK: return "ok";
        case FNV1A_64_MIX_C11_D58_ERR_NULL: return "null pointer supplied";
        case FNV1A_64_MIX_C11_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FNV1A_64_MIX_C11_D58_ERR_INVALID: return "domain precondition violated";
        case FNV1A_64_MIX_C11_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FNV1A_64_MIX_C11_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FNV1A_64_MIX_C11_D58_ERRORS_H */
