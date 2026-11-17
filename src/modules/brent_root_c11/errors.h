#ifndef BRENT_ROOT_C11_ERRORS_H
#define BRENT_ROOT_C11_ERRORS_H

typedef enum brent_root_c11_err {
    BRENT_ROOT_C11_OK = 0,
    BRENT_ROOT_C11_ERR_NULL = -1,
    BRENT_ROOT_C11_ERR_BOUNDS = -2,
    BRENT_ROOT_C11_ERR_INVALID = -3,
    BRENT_ROOT_C11_ERR_OVERFLOW = -4,
    BRENT_ROOT_C11_ERR_INVARIANT = -5
} brent_root_c11_err_t;



static inline const char* brent_root_c11_err_str(brent_root_c11_err_t err) {
    switch (err) {
        case BRENT_ROOT_C11_OK: return "ok";
        case BRENT_ROOT_C11_ERR_NULL: return "null pointer supplied";
        case BRENT_ROOT_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BRENT_ROOT_C11_ERR_INVALID: return "domain precondition violated";
        case BRENT_ROOT_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BRENT_ROOT_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BRENT_ROOT_C11_ERRORS_H */
