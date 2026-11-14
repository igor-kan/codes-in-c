/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for In-Place LU Decomposition Matrix Inversion with Solve.
 * Module: matrix_inversion_lu
 */

typedef enum matrix_inversion_lu_error_status {
    MATRIX_INVERSION_LU_OK = 0,
    MATRIX_INVERSION_LU_ERR_INVALID_PARAM = -10,
    MATRIX_INVERSION_LU_ERR_CAPACITY_LIMIT = -11,
    MATRIX_INVERSION_LU_ERR_NUMERICAL_FAULT = -12
} matrix_inversion_lu_error_status_t;

const char* matrix_inversion_lu_error_string(matrix_inversion_lu_error_status_t err) {
    switch (err) {
        case MATRIX_INVERSION_LU_OK: return "Operational success";
        case MATRIX_INVERSION_LU_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case MATRIX_INVERSION_LU_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case MATRIX_INVERSION_LU_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
