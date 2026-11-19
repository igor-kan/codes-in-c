#ifndef Z_ALGORITHM_LCP_C11_ERRORS_H
#define Z_ALGORITHM_LCP_C11_ERRORS_H

typedef enum z_algorithm_lcp_c11_err {
    Z_ALGORITHM_LCP_C11_OK = 0,
    Z_ALGORITHM_LCP_C11_ERR_NULL = -1,
    Z_ALGORITHM_LCP_C11_ERR_BOUNDS = -2,
    Z_ALGORITHM_LCP_C11_ERR_INVALID = -3,
    Z_ALGORITHM_LCP_C11_ERR_OVERFLOW = -4,
    Z_ALGORITHM_LCP_C11_ERR_INVARIANT = -5
} z_algorithm_lcp_c11_err_t;



static inline const char* z_algorithm_lcp_c11_err_str(z_algorithm_lcp_c11_err_t err) {
    switch (err) {
        case Z_ALGORITHM_LCP_C11_OK: return "ok";
        case Z_ALGORITHM_LCP_C11_ERR_NULL: return "null pointer supplied";
        case Z_ALGORITHM_LCP_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case Z_ALGORITHM_LCP_C11_ERR_INVALID: return "domain precondition violated";
        case Z_ALGORITHM_LCP_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case Z_ALGORITHM_LCP_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* Z_ALGORITHM_LCP_C11_ERRORS_H */
