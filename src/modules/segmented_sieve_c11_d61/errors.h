#ifndef SEGMENTED_SIEVE_C11_D61_ERRORS_H
#define SEGMENTED_SIEVE_C11_D61_ERRORS_H

typedef enum segmented_sieve_c11_d61_err {
    SEGMENTED_SIEVE_C11_D61_OK = 0,
    SEGMENTED_SIEVE_C11_D61_ERR_NULL = -1,
    SEGMENTED_SIEVE_C11_D61_ERR_BOUNDS = -2,
    SEGMENTED_SIEVE_C11_D61_ERR_INVALID = -3,
    SEGMENTED_SIEVE_C11_D61_ERR_OVERFLOW = -4,
    SEGMENTED_SIEVE_C11_D61_ERR_INVARIANT = -5
} segmented_sieve_c11_d61_err_t;



static inline const char* segmented_sieve_c11_d61_err_str(segmented_sieve_c11_d61_err_t err) {
    switch (err) {
        case SEGMENTED_SIEVE_C11_D61_OK: return "ok";
        case SEGMENTED_SIEVE_C11_D61_ERR_NULL: return "null pointer supplied";
        case SEGMENTED_SIEVE_C11_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SEGMENTED_SIEVE_C11_D61_ERR_INVALID: return "domain precondition violated";
        case SEGMENTED_SIEVE_C11_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SEGMENTED_SIEVE_C11_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SEGMENTED_SIEVE_C11_D61_ERRORS_H */
