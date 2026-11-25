#ifndef MILLER_RABIN_DET64_D60_ERRORS_H
#define MILLER_RABIN_DET64_D60_ERRORS_H

typedef enum miller_rabin_det64_d60_err {
    MILLER_RABIN_DET64_D60_OK = 0,
    MILLER_RABIN_DET64_D60_ERR_NULL = -1,
    MILLER_RABIN_DET64_D60_ERR_BOUNDS = -2,
    MILLER_RABIN_DET64_D60_ERR_INVALID = -3,
    MILLER_RABIN_DET64_D60_ERR_OVERFLOW = -4,
    MILLER_RABIN_DET64_D60_ERR_INVARIANT = -5
} miller_rabin_det64_d60_err_t;



static inline const char* miller_rabin_det64_d60_err_str(miller_rabin_det64_d60_err_t err) {
    switch (err) {
        case MILLER_RABIN_DET64_D60_OK: return "ok";
        case MILLER_RABIN_DET64_D60_ERR_NULL: return "null pointer supplied";
        case MILLER_RABIN_DET64_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case MILLER_RABIN_DET64_D60_ERR_INVALID: return "domain precondition violated";
        case MILLER_RABIN_DET64_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case MILLER_RABIN_DET64_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* MILLER_RABIN_DET64_D60_ERRORS_H */
