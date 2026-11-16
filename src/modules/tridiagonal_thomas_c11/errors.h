#ifndef TRIDIAGONAL_THOMAS_C11_ERRORS_H
#define TRIDIAGONAL_THOMAS_C11_ERRORS_H

typedef enum tridiagonal_thomas_c11_err {
    TRIDIAGONAL_THOMAS_C11_OK = 0,
    TRIDIAGONAL_THOMAS_C11_ERR_NULL = -1,
    TRIDIAGONAL_THOMAS_C11_ERR_BOUNDS = -2,
    TRIDIAGONAL_THOMAS_C11_ERR_INVALID = -3,
    TRIDIAGONAL_THOMAS_C11_ERR_OVERFLOW = -4,
    TRIDIAGONAL_THOMAS_C11_ERR_INVARIANT = -5
} tridiagonal_thomas_c11_err_t;



static inline const char* tridiagonal_thomas_c11_err_str(tridiagonal_thomas_c11_err_t err) {
    switch (err) {
        case TRIDIAGONAL_THOMAS_C11_OK: return "ok";
        case TRIDIAGONAL_THOMAS_C11_ERR_NULL: return "null pointer supplied";
        case TRIDIAGONAL_THOMAS_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TRIDIAGONAL_THOMAS_C11_ERR_INVALID: return "domain precondition violated";
        case TRIDIAGONAL_THOMAS_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TRIDIAGONAL_THOMAS_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TRIDIAGONAL_THOMAS_C11_ERRORS_H */
