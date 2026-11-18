#ifndef BINOMIAL_HEAP_MELD_C11_ERRORS_H
#define BINOMIAL_HEAP_MELD_C11_ERRORS_H

typedef enum binomial_heap_meld_c11_err {
    BINOMIAL_HEAP_MELD_C11_OK = 0,
    BINOMIAL_HEAP_MELD_C11_ERR_NULL = -1,
    BINOMIAL_HEAP_MELD_C11_ERR_BOUNDS = -2,
    BINOMIAL_HEAP_MELD_C11_ERR_INVALID = -3,
    BINOMIAL_HEAP_MELD_C11_ERR_OVERFLOW = -4,
    BINOMIAL_HEAP_MELD_C11_ERR_INVARIANT = -5
} binomial_heap_meld_c11_err_t;



static inline const char* binomial_heap_meld_c11_err_str(binomial_heap_meld_c11_err_t err) {
    switch (err) {
        case BINOMIAL_HEAP_MELD_C11_OK: return "ok";
        case BINOMIAL_HEAP_MELD_C11_ERR_NULL: return "null pointer supplied";
        case BINOMIAL_HEAP_MELD_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BINOMIAL_HEAP_MELD_C11_ERR_INVALID: return "domain precondition violated";
        case BINOMIAL_HEAP_MELD_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BINOMIAL_HEAP_MELD_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BINOMIAL_HEAP_MELD_C11_ERRORS_H */
