/**
 * @file errors.c
 * @brief Rich diagnostic error reporting for Kernel-Style Slab Cache Memory Pool Allocator.
 * Module: slab_cache_allocator
 */

typedef enum slab_cache_allocator_error {
    SLAB_CACHE_ALLOCATOR_OK = 0,
    SLAB_CACHE_ALLOCATOR_ERR_NULL = -100,
    SLAB_CACHE_ALLOCATOR_ERR_CAPACITY = -101,
    SLAB_CACHE_ALLOCATOR_ERR_CONVERGENCE = -102
} slab_cache_allocator_error_t;

const char* slab_cache_allocator_strerror(slab_cache_allocator_error_t err) {
    switch (err) {
        case SLAB_CACHE_ALLOCATOR_OK: return "Success";
        case SLAB_CACHE_ALLOCATOR_ERR_NULL: return "Encountered null pointer argument";
        case SLAB_CACHE_ALLOCATOR_ERR_CAPACITY: return "Capacity limit exceeded";
        case SLAB_CACHE_ALLOCATOR_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
