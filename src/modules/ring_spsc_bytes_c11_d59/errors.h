#ifndef RING_SPSC_BYTES_C11_D59_ERRORS_H
#define RING_SPSC_BYTES_C11_D59_ERRORS_H

typedef enum ring_spsc_bytes_c11_d59_err {
    RING_SPSC_BYTES_C11_D59_OK = 0,
    RING_SPSC_BYTES_C11_D59_ERR_NULL = -1,
    RING_SPSC_BYTES_C11_D59_ERR_BOUNDS = -2,
    RING_SPSC_BYTES_C11_D59_ERR_INVALID = -3,
    RING_SPSC_BYTES_C11_D59_ERR_OVERFLOW = -4,
    RING_SPSC_BYTES_C11_D59_ERR_INVARIANT = -5
} ring_spsc_bytes_c11_d59_err_t;



static inline const char* ring_spsc_bytes_c11_d59_err_str(ring_spsc_bytes_c11_d59_err_t err) {
    switch (err) {
        case RING_SPSC_BYTES_C11_D59_OK: return "ok";
        case RING_SPSC_BYTES_C11_D59_ERR_NULL: return "null pointer supplied";
        case RING_SPSC_BYTES_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RING_SPSC_BYTES_C11_D59_ERR_INVALID: return "domain precondition violated";
        case RING_SPSC_BYTES_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RING_SPSC_BYTES_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RING_SPSC_BYTES_C11_D59_ERRORS_H */
