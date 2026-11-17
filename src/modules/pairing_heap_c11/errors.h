#ifndef PAIRING_HEAP_C11_ERRORS_H
#define PAIRING_HEAP_C11_ERRORS_H

typedef enum pairing_heap_c11_err {
    PAIRING_HEAP_C11_OK = 0,
    PAIRING_HEAP_C11_ERR_NULL = -1,
    PAIRING_HEAP_C11_ERR_BOUNDS = -2,
    PAIRING_HEAP_C11_ERR_INVALID = -3,
    PAIRING_HEAP_C11_ERR_OVERFLOW = -4,
    PAIRING_HEAP_C11_ERR_INVARIANT = -5
} pairing_heap_c11_err_t;



static inline const char* pairing_heap_c11_err_str(pairing_heap_c11_err_t err) {
    switch (err) {
        case PAIRING_HEAP_C11_OK: return "ok";
        case PAIRING_HEAP_C11_ERR_NULL: return "null pointer supplied";
        case PAIRING_HEAP_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case PAIRING_HEAP_C11_ERR_INVALID: return "domain precondition violated";
        case PAIRING_HEAP_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case PAIRING_HEAP_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* PAIRING_HEAP_C11_ERRORS_H */
