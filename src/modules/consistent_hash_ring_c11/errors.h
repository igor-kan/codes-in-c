#ifndef CONSISTENT_HASH_RING_C11_ERRORS_H
#define CONSISTENT_HASH_RING_C11_ERRORS_H

typedef enum consistent_hash_ring_c11_err {
    CONSISTENT_HASH_RING_C11_OK = 0,
    CONSISTENT_HASH_RING_C11_ERR_NULL = -1,
    CONSISTENT_HASH_RING_C11_ERR_BOUNDS = -2,
    CONSISTENT_HASH_RING_C11_ERR_INVALID = -3,
    CONSISTENT_HASH_RING_C11_ERR_OVERFLOW = -4,
    CONSISTENT_HASH_RING_C11_ERR_INVARIANT = -5
} consistent_hash_ring_c11_err_t;



static inline const char* consistent_hash_ring_c11_err_str(consistent_hash_ring_c11_err_t err) {
    switch (err) {
        case CONSISTENT_HASH_RING_C11_OK: return "ok";
        case CONSISTENT_HASH_RING_C11_ERR_NULL: return "null pointer supplied";
        case CONSISTENT_HASH_RING_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case CONSISTENT_HASH_RING_C11_ERR_INVALID: return "domain precondition violated";
        case CONSISTENT_HASH_RING_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case CONSISTENT_HASH_RING_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* CONSISTENT_HASH_RING_C11_ERRORS_H */
