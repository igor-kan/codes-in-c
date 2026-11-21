#ifndef SPSC_LOCKFREE_RING_C11_ERRORS_H
#define SPSC_LOCKFREE_RING_C11_ERRORS_H

typedef enum spsc_lockfree_ring_c11_err {
    SPSC_LOCKFREE_RING_C11_OK = 0,
    SPSC_LOCKFREE_RING_C11_ERR_NULL = -1,
    SPSC_LOCKFREE_RING_C11_ERR_BOUNDS = -2,
    SPSC_LOCKFREE_RING_C11_ERR_INVALID = -3,
    SPSC_LOCKFREE_RING_C11_ERR_OVERFLOW = -4,
    SPSC_LOCKFREE_RING_C11_ERR_INVARIANT = -5
} spsc_lockfree_ring_c11_err_t;



static inline const char* spsc_lockfree_ring_c11_err_str(spsc_lockfree_ring_c11_err_t err) {
    switch (err) {
        case SPSC_LOCKFREE_RING_C11_OK: return "ok";
        case SPSC_LOCKFREE_RING_C11_ERR_NULL: return "null pointer supplied";
        case SPSC_LOCKFREE_RING_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SPSC_LOCKFREE_RING_C11_ERR_INVALID: return "domain precondition violated";
        case SPSC_LOCKFREE_RING_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SPSC_LOCKFREE_RING_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SPSC_LOCKFREE_RING_C11_ERRORS_H */
