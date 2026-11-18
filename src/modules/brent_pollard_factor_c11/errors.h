#ifndef BRENT_POLLARD_FACTOR_C11_ERRORS_H
#define BRENT_POLLARD_FACTOR_C11_ERRORS_H

typedef enum brent_pollard_factor_c11_err {
    BRENT_POLLARD_FACTOR_C11_OK = 0,
    BRENT_POLLARD_FACTOR_C11_ERR_NULL = -1,
    BRENT_POLLARD_FACTOR_C11_ERR_BOUNDS = -2,
    BRENT_POLLARD_FACTOR_C11_ERR_INVALID = -3,
    BRENT_POLLARD_FACTOR_C11_ERR_OVERFLOW = -4,
    BRENT_POLLARD_FACTOR_C11_ERR_INVARIANT = -5
} brent_pollard_factor_c11_err_t;



static inline const char* brent_pollard_factor_c11_err_str(brent_pollard_factor_c11_err_t err) {
    switch (err) {
        case BRENT_POLLARD_FACTOR_C11_OK: return "ok";
        case BRENT_POLLARD_FACTOR_C11_ERR_NULL: return "null pointer supplied";
        case BRENT_POLLARD_FACTOR_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BRENT_POLLARD_FACTOR_C11_ERR_INVALID: return "domain precondition violated";
        case BRENT_POLLARD_FACTOR_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BRENT_POLLARD_FACTOR_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BRENT_POLLARD_FACTOR_C11_ERRORS_H */
