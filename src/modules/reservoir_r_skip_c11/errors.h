#ifndef RESERVOIR_R_SKIP_C11_ERRORS_H
#define RESERVOIR_R_SKIP_C11_ERRORS_H

typedef enum reservoir_r_skip_c11_err {
    RESERVOIR_R_SKIP_C11_OK = 0,
    RESERVOIR_R_SKIP_C11_ERR_NULL = -1,
    RESERVOIR_R_SKIP_C11_ERR_BOUNDS = -2,
    RESERVOIR_R_SKIP_C11_ERR_INVALID = -3,
    RESERVOIR_R_SKIP_C11_ERR_OVERFLOW = -4,
    RESERVOIR_R_SKIP_C11_ERR_INVARIANT = -5
} reservoir_r_skip_c11_err_t;



static inline const char* reservoir_r_skip_c11_err_str(reservoir_r_skip_c11_err_t err) {
    switch (err) {
        case RESERVOIR_R_SKIP_C11_OK: return "ok";
        case RESERVOIR_R_SKIP_C11_ERR_NULL: return "null pointer supplied";
        case RESERVOIR_R_SKIP_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RESERVOIR_R_SKIP_C11_ERR_INVALID: return "domain precondition violated";
        case RESERVOIR_R_SKIP_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RESERVOIR_R_SKIP_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RESERVOIR_R_SKIP_C11_ERRORS_H */
