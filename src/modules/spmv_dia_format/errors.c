/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Diagonal (DIA) Sparse Matrix-Vector Multiply for Banded.
 * Module: spmv_dia_format
 */

typedef enum spmv_dia_format_error_status {
    SPMV_DIA_FORMAT_OK = 0,
    SPMV_DIA_FORMAT_ERR_INVALID_PARAM = -10,
    SPMV_DIA_FORMAT_ERR_CAPACITY_LIMIT = -11,
    SPMV_DIA_FORMAT_ERR_NUMERICAL_FAULT = -12
} spmv_dia_format_error_status_t;

const char* spmv_dia_format_error_string(spmv_dia_format_error_status_t err) {
    switch (err) {
        case SPMV_DIA_FORMAT_OK: return "Operational success";
        case SPMV_DIA_FORMAT_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case SPMV_DIA_FORMAT_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case SPMV_DIA_FORMAT_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
