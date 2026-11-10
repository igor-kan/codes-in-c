/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Lock-Free Treiber Stack Freelist with ABA Version Tagging.
 * Module: lockfree_freelist
 */

typedef enum lockfree_freelist_error_code {
    LOCKFREE_FREELIST_STATUS_OK = 0,
    LOCKFREE_FREELIST_ERR_NULL_PTR = -10,
    LOCKFREE_FREELIST_ERR_OUT_OF_BOUNDS = -11,
    LOCKFREE_FREELIST_ERR_DIVERGENCE = -12
} lockfree_freelist_error_code_t;

const char* lockfree_freelist_error_message(lockfree_freelist_error_code_t code) {
    switch (code) {
        case LOCKFREE_FREELIST_STATUS_OK: return "Operational success";
        case LOCKFREE_FREELIST_ERR_NULL_PTR: return "Null pointer argument";
        case LOCKFREE_FREELIST_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case LOCKFREE_FREELIST_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
