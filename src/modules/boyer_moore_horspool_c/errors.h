#ifndef BOYER_MOORE_HORSPOOL_C_ERRORS_H
#define BOYER_MOORE_HORSPOOL_C_ERRORS_H

typedef enum boyer_moore_horspool_c_err {
    BOYER_MOORE_HORSPOOL_C_OK = 0,
    BOYER_MOORE_HORSPOOL_C_ERR_NULL = -1,
    BOYER_MOORE_HORSPOOL_C_ERR_BOUNDS = -2,
    BOYER_MOORE_HORSPOOL_C_ERR_INVALID = -3,
    BOYER_MOORE_HORSPOOL_C_ERR_OVERFLOW = -4,
    BOYER_MOORE_HORSPOOL_C_ERR_INVARIANT = -5
} boyer_moore_horspool_c_err_t;



static inline const char* boyer_moore_horspool_c_err_str(boyer_moore_horspool_c_err_t err) {
    switch (err) {
        case BOYER_MOORE_HORSPOOL_C_OK: return "ok";
        case BOYER_MOORE_HORSPOOL_C_ERR_NULL: return "null pointer supplied";
        case BOYER_MOORE_HORSPOOL_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BOYER_MOORE_HORSPOOL_C_ERR_INVALID: return "domain precondition violated";
        case BOYER_MOORE_HORSPOOL_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BOYER_MOORE_HORSPOOL_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BOYER_MOORE_HORSPOOL_C_ERRORS_H */
