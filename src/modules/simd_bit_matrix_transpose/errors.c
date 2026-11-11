/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for 64x64 Bit Matrix Transposition using Vector Bitmasks.
 * Module: simd_bit_matrix_transpose
 */

typedef enum simd_bit_matrix_transpose_error_code {
    SIMD_BIT_MATRIX_TRANSPOSE_STATUS_OK = 0,
    SIMD_BIT_MATRIX_TRANSPOSE_ERR_NULL_PTR = -20,
    SIMD_BIT_MATRIX_TRANSPOSE_ERR_OUT_OF_BOUNDS = -21,
    SIMD_BIT_MATRIX_TRANSPOSE_ERR_DIVERGENCE = -22
} simd_bit_matrix_transpose_error_code_t;

const char* simd_bit_matrix_transpose_error_message(simd_bit_matrix_transpose_error_code_t code) {
    switch (code) {
        case SIMD_BIT_MATRIX_TRANSPOSE_STATUS_OK: return "Operational success";
        case SIMD_BIT_MATRIX_TRANSPOSE_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_BIT_MATRIX_TRANSPOSE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_BIT_MATRIX_TRANSPOSE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
