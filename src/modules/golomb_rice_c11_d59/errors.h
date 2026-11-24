#ifndef GOLOMB_RICE_C11_D59_ERRORS_H
#define GOLOMB_RICE_C11_D59_ERRORS_H

typedef enum golomb_rice_c11_d59_err {
    GOLOMB_RICE_C11_D59_OK = 0,
    GOLOMB_RICE_C11_D59_ERR_NULL = -1,
    GOLOMB_RICE_C11_D59_ERR_BOUNDS = -2,
    GOLOMB_RICE_C11_D59_ERR_INVALID = -3,
    GOLOMB_RICE_C11_D59_ERR_OVERFLOW = -4,
    GOLOMB_RICE_C11_D59_ERR_INVARIANT = -5
} golomb_rice_c11_d59_err_t;



static inline const char* golomb_rice_c11_d59_err_str(golomb_rice_c11_d59_err_t err) {
    switch (err) {
        case GOLOMB_RICE_C11_D59_OK: return "ok";
        case GOLOMB_RICE_C11_D59_ERR_NULL: return "null pointer supplied";
        case GOLOMB_RICE_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case GOLOMB_RICE_C11_D59_ERR_INVALID: return "domain precondition violated";
        case GOLOMB_RICE_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case GOLOMB_RICE_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* GOLOMB_RICE_C11_D59_ERRORS_H */
