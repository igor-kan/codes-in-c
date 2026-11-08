/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for AVX2 Cacheline-Aligned Matrix Transposition.
 * Module: simd_matrix_transpose
 */

typedef enum simd_matrix_transpose_error {
    SIMD_MATRIX_TRANSPOSE_OK = 0,
    SIMD_MATRIX_TRANSPOSE_ERR_NULL = -100,
    SIMD_MATRIX_TRANSPOSE_ERR_CAPACITY = -101,
    SIMD_MATRIX_TRANSPOSE_ERR_CONVERGENCE = -102
} simd_matrix_transpose_error_t;

const char* simd_matrix_transpose_strerror(simd_matrix_transpose_error_t err) {
    switch (err) {
        case SIMD_MATRIX_TRANSPOSE_OK: return "Success";
        case SIMD_MATRIX_TRANSPOSE_ERR_NULL: return "Encountered null pointer argument";
        case SIMD_MATRIX_TRANSPOSE_ERR_CAPACITY: return "Capacity limit exceeded";
        case SIMD_MATRIX_TRANSPOSE_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
