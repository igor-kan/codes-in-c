/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Cacheline-Aligned Fixed-Size Block Pool with Bitmask.
 * Module: memory_pool_fixed
 */

typedef enum memory_pool_fixed_error_code {
    MEMORY_POOL_FIXED_STATUS_OK = 0,
    MEMORY_POOL_FIXED_ERR_NULL_PTR = -20,
    MEMORY_POOL_FIXED_ERR_OUT_OF_BOUNDS = -21,
    MEMORY_POOL_FIXED_ERR_DIVERGENCE = -22
} memory_pool_fixed_error_code_t;

const char* memory_pool_fixed_error_message(memory_pool_fixed_error_code_t code) {
    switch (code) {
        case MEMORY_POOL_FIXED_STATUS_OK: return "Operational success";
        case MEMORY_POOL_FIXED_ERR_NULL_PTR: return "Null pointer argument";
        case MEMORY_POOL_FIXED_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case MEMORY_POOL_FIXED_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
