#ifndef DARY_HEAP_C11_D61_ERRORS_H
#define DARY_HEAP_C11_D61_ERRORS_H

typedef enum dary_heap_c11_d61_err {
    DARY_HEAP_C11_D61_OK = 0,
    DARY_HEAP_C11_D61_ERR_NULL = -1,
    DARY_HEAP_C11_D61_ERR_BOUNDS = -2,
    DARY_HEAP_C11_D61_ERR_INVALID = -3,
    DARY_HEAP_C11_D61_ERR_OVERFLOW = -4,
    DARY_HEAP_C11_D61_ERR_INVARIANT = -5
} dary_heap_c11_d61_err_t;



static inline const char* dary_heap_c11_d61_err_str(dary_heap_c11_d61_err_t err) {
    switch (err) {
        case DARY_HEAP_C11_D61_OK: return "ok";
        case DARY_HEAP_C11_D61_ERR_NULL: return "null pointer supplied";
        case DARY_HEAP_C11_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case DARY_HEAP_C11_D61_ERR_INVALID: return "domain precondition violated";
        case DARY_HEAP_C11_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case DARY_HEAP_C11_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* DARY_HEAP_C11_D61_ERRORS_H */
