/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for ELLPACK Sparse Matrix-Vector Multiply with AVX2.
 * Module: simd_spmv_ellpack
 */

typedef enum simd_spmv_ellpack_error_code {
    SIMD_SPMV_ELLPACK_STATUS_OK = 0,
    SIMD_SPMV_ELLPACK_ERR_NULL_PTR = -10,
    SIMD_SPMV_ELLPACK_ERR_OUT_OF_BOUNDS = -11,
    SIMD_SPMV_ELLPACK_ERR_DIVERGENCE = -12
} simd_spmv_ellpack_error_code_t;

const char* simd_spmv_ellpack_error_message(simd_spmv_ellpack_error_code_t code) {
    switch (code) {
        case SIMD_SPMV_ELLPACK_STATUS_OK: return "Operational success";
        case SIMD_SPMV_ELLPACK_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_SPMV_ELLPACK_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_SPMV_ELLPACK_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
