#ifndef PATIENCE_LIS_RECONSTRUCT_C_ERRORS_H
#define PATIENCE_LIS_RECONSTRUCT_C_ERRORS_H

typedef enum patience_lis_reconstruct_c_err {
    PATIENCE_LIS_RECONSTRUCT_C_OK = 0,
    PATIENCE_LIS_RECONSTRUCT_C_ERR_NULL = -1,
    PATIENCE_LIS_RECONSTRUCT_C_ERR_BOUNDS = -2,
    PATIENCE_LIS_RECONSTRUCT_C_ERR_INVALID = -3,
    PATIENCE_LIS_RECONSTRUCT_C_ERR_OVERFLOW = -4,
    PATIENCE_LIS_RECONSTRUCT_C_ERR_INVARIANT = -5
} patience_lis_reconstruct_c_err_t;



static inline const char* patience_lis_reconstruct_c_err_str(patience_lis_reconstruct_c_err_t err) {
    switch (err) {
        case PATIENCE_LIS_RECONSTRUCT_C_OK: return "ok";
        case PATIENCE_LIS_RECONSTRUCT_C_ERR_NULL: return "null pointer supplied";
        case PATIENCE_LIS_RECONSTRUCT_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PATIENCE_LIS_RECONSTRUCT_C_ERR_INVALID: return "domain precondition violated";
        case PATIENCE_LIS_RECONSTRUCT_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PATIENCE_LIS_RECONSTRUCT_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PATIENCE_LIS_RECONSTRUCT_C_ERRORS_H */
