#ifndef PEARSON_R_CORR_C11_D59_ERRORS_H
#define PEARSON_R_CORR_C11_D59_ERRORS_H

typedef enum pearson_r_corr_c11_d59_err {
    PEARSON_R_CORR_C11_D59_OK = 0,
    PEARSON_R_CORR_C11_D59_ERR_NULL = -1,
    PEARSON_R_CORR_C11_D59_ERR_BOUNDS = -2,
    PEARSON_R_CORR_C11_D59_ERR_INVALID = -3,
    PEARSON_R_CORR_C11_D59_ERR_OVERFLOW = -4,
    PEARSON_R_CORR_C11_D59_ERR_INVARIANT = -5
} pearson_r_corr_c11_d59_err_t;



static inline const char* pearson_r_corr_c11_d59_err_str(pearson_r_corr_c11_d59_err_t err) {
    switch (err) {
        case PEARSON_R_CORR_C11_D59_OK: return "ok";
        case PEARSON_R_CORR_C11_D59_ERR_NULL: return "null pointer supplied";
        case PEARSON_R_CORR_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PEARSON_R_CORR_C11_D59_ERR_INVALID: return "domain precondition violated";
        case PEARSON_R_CORR_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PEARSON_R_CORR_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PEARSON_R_CORR_C11_D59_ERRORS_H */
