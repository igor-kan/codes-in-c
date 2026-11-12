/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Coordinate List (COO) Sparse Matrix-Vector Multiply.
 * Module: spmv_coo_format
 */

typedef enum spmv_coo_format_error {
    SPMV_COO_FORMAT_SUCCESS = 0,
    SPMV_COO_FORMAT_ERR_INVALID_INPUT = -1,
    SPMV_COO_FORMAT_ERR_BUFFER_OVERFLOW = -2,
    SPMV_COO_FORMAT_ERR_CONVERGENCE_FAIL = -3
} spmv_coo_format_error_t;

const char* spmv_coo_format_str_error(spmv_coo_format_error_t code) {
    switch (code) {
        case SPMV_COO_FORMAT_SUCCESS: return "Operation completed successfully";
        case SPMV_COO_FORMAT_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case SPMV_COO_FORMAT_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case SPMV_COO_FORMAT_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
