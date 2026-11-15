#ifndef BURROWS_WHEELER_BWT_ERRORS_H
#define BURROWS_WHEELER_BWT_ERRORS_H

typedef enum burrows_wheeler_bwt_err {
    BURROWS_WHEELER_BWT_OK = 0,
    BURROWS_WHEELER_BWT_ERR_NULL = -1,
    BURROWS_WHEELER_BWT_ERR_BOUNDS = -2,
    BURROWS_WHEELER_BWT_ERR_INVALID = -3,
    BURROWS_WHEELER_BWT_ERR_OVERFLOW = -4,
    BURROWS_WHEELER_BWT_ERR_INVARIANT = -5
} burrows_wheeler_bwt_err_t;



static inline const char* burrows_wheeler_bwt_err_str(burrows_wheeler_bwt_err_t err) {
    switch (err) {
        case BURROWS_WHEELER_BWT_OK: return "ok";
        case BURROWS_WHEELER_BWT_ERR_NULL: return "null pointer supplied";
        case BURROWS_WHEELER_BWT_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BURROWS_WHEELER_BWT_ERR_INVALID: return "domain precondition violated";
        case BURROWS_WHEELER_BWT_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BURROWS_WHEELER_BWT_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BURROWS_WHEELER_BWT_ERRORS_H */
