#ifndef BLOOM_QUOTIENT_FILTER_ERRORS_H
#define BLOOM_QUOTIENT_FILTER_ERRORS_H

typedef enum bloom_quotient_filter_err {
    BLOOM_QUOTIENT_FILTER_OK = 0,
    BLOOM_QUOTIENT_FILTER_ERR_NULL = -1,
    BLOOM_QUOTIENT_FILTER_ERR_BOUNDS = -2,
    BLOOM_QUOTIENT_FILTER_ERR_INVALID = -3,
    BLOOM_QUOTIENT_FILTER_ERR_OVERFLOW = -4,
    BLOOM_QUOTIENT_FILTER_ERR_INVARIANT = -5
} bloom_quotient_filter_err_t;



static inline const char* bloom_quotient_filter_err_str(bloom_quotient_filter_err_t err) {
    switch (err) {
        case BLOOM_QUOTIENT_FILTER_OK: return "ok";
        case BLOOM_QUOTIENT_FILTER_ERR_NULL: return "null pointer supplied";
        case BLOOM_QUOTIENT_FILTER_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BLOOM_QUOTIENT_FILTER_ERR_INVALID: return "domain precondition violated";
        case BLOOM_QUOTIENT_FILTER_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BLOOM_QUOTIENT_FILTER_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BLOOM_QUOTIENT_FILTER_ERRORS_H */
