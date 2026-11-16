#ifndef KFIFO_POWER2_RING_ERRORS_H
#define KFIFO_POWER2_RING_ERRORS_H

typedef enum kfifo_power2_ring_err {
    KFIFO_POWER2_RING_OK = 0,
    KFIFO_POWER2_RING_ERR_NULL = -1,
    KFIFO_POWER2_RING_ERR_BOUNDS = -2,
    KFIFO_POWER2_RING_ERR_INVALID = -3,
    KFIFO_POWER2_RING_ERR_OVERFLOW = -4,
    KFIFO_POWER2_RING_ERR_INVARIANT = -5
} kfifo_power2_ring_err_t;



static inline const char* kfifo_power2_ring_err_str(kfifo_power2_ring_err_t err) {
    switch (err) {
        case KFIFO_POWER2_RING_OK: return "ok";
        case KFIFO_POWER2_RING_ERR_NULL: return "null pointer supplied";
        case KFIFO_POWER2_RING_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case KFIFO_POWER2_RING_ERR_INVALID: return "domain precondition violated";
        case KFIFO_POWER2_RING_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case KFIFO_POWER2_RING_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* KFIFO_POWER2_RING_ERRORS_H */
