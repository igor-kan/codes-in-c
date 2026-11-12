/**
 * @file errors.c
 * @brief Domain diagnostic error codes and messages for Gauss-Jordan Matrix Inversion with Partial Pivoting.
 * Module: matrix_gauss_jordan
 */

typedef enum matrix_gauss_jordan_error {
    MATRIX_GAUSS_JORDAN_SUCCESS = 0,
    MATRIX_GAUSS_JORDAN_ERR_INVALID_INPUT = -1,
    MATRIX_GAUSS_JORDAN_ERR_BUFFER_OVERFLOW = -2,
    MATRIX_GAUSS_JORDAN_ERR_CONVERGENCE_FAIL = -3
} matrix_gauss_jordan_error_t;

const char* matrix_gauss_jordan_str_error(matrix_gauss_jordan_error_t code) {
    switch (code) {
        case MATRIX_GAUSS_JORDAN_SUCCESS: return "Operation completed successfully";
        case MATRIX_GAUSS_JORDAN_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case MATRIX_GAUSS_JORDAN_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case MATRIX_GAUSS_JORDAN_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
