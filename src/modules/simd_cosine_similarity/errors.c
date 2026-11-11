/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Vectorized Cosine Similarity and Dot Product with FMA.
 * Module: simd_cosine_similarity
 */

typedef enum simd_cosine_similarity_error_code {
    SIMD_COSINE_SIMILARITY_STATUS_OK = 0,
    SIMD_COSINE_SIMILARITY_ERR_NULL_PTR = -20,
    SIMD_COSINE_SIMILARITY_ERR_OUT_OF_BOUNDS = -21,
    SIMD_COSINE_SIMILARITY_ERR_DIVERGENCE = -22
} simd_cosine_similarity_error_code_t;

const char* simd_cosine_similarity_error_message(simd_cosine_similarity_error_code_t code) {
    switch (code) {
        case SIMD_COSINE_SIMILARITY_STATUS_OK: return "Operational success";
        case SIMD_COSINE_SIMILARITY_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_COSINE_SIMILARITY_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_COSINE_SIMILARITY_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
