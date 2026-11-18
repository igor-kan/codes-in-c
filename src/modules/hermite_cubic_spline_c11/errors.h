#ifndef HERMITE_CUBIC_SPLINE_C11_ERRORS_H
#define HERMITE_CUBIC_SPLINE_C11_ERRORS_H

typedef enum hermite_cubic_spline_c11_err {
    HERMITE_CUBIC_SPLINE_C11_OK = 0,
    HERMITE_CUBIC_SPLINE_C11_ERR_NULL = -1,
    HERMITE_CUBIC_SPLINE_C11_ERR_BOUNDS = -2,
    HERMITE_CUBIC_SPLINE_C11_ERR_INVALID = -3,
    HERMITE_CUBIC_SPLINE_C11_ERR_OVERFLOW = -4,
    HERMITE_CUBIC_SPLINE_C11_ERR_INVARIANT = -5
} hermite_cubic_spline_c11_err_t;



static inline const char* hermite_cubic_spline_c11_err_str(hermite_cubic_spline_c11_err_t err) {
    switch (err) {
        case HERMITE_CUBIC_SPLINE_C11_OK: return "ok";
        case HERMITE_CUBIC_SPLINE_C11_ERR_NULL: return "null pointer supplied";
        case HERMITE_CUBIC_SPLINE_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case HERMITE_CUBIC_SPLINE_C11_ERR_INVALID: return "domain precondition violated";
        case HERMITE_CUBIC_SPLINE_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case HERMITE_CUBIC_SPLINE_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* HERMITE_CUBIC_SPLINE_C11_ERRORS_H */
