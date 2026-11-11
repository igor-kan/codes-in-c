/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

typedef enum jemalloc_run_cache_error_code {
    JEMALLOC_RUN_CACHE_STATUS_OK = 0,
    JEMALLOC_RUN_CACHE_ERR_NULL_PTR = -20,
    JEMALLOC_RUN_CACHE_ERR_OUT_OF_BOUNDS = -21,
    JEMALLOC_RUN_CACHE_ERR_DIVERGENCE = -22
} jemalloc_run_cache_error_code_t;

const char* jemalloc_run_cache_error_message(jemalloc_run_cache_error_code_t code) {
    switch (code) {
        case JEMALLOC_RUN_CACHE_STATUS_OK: return "Operational success";
        case JEMALLOC_RUN_CACHE_ERR_NULL_PTR: return "Null pointer argument";
        case JEMALLOC_RUN_CACHE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case JEMALLOC_RUN_CACHE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
