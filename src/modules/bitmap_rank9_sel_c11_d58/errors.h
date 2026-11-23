#ifndef BITMAP_RANK9_SEL_C11_D58_ERRORS_H
#define BITMAP_RANK9_SEL_C11_D58_ERRORS_H

typedef enum bitmap_rank9_sel_c11_d58_err {
    BITMAP_RANK9_SEL_C11_D58_OK = 0,
    BITMAP_RANK9_SEL_C11_D58_ERR_NULL = -1,
    BITMAP_RANK9_SEL_C11_D58_ERR_BOUNDS = -2,
    BITMAP_RANK9_SEL_C11_D58_ERR_INVALID = -3,
    BITMAP_RANK9_SEL_C11_D58_ERR_OVERFLOW = -4,
    BITMAP_RANK9_SEL_C11_D58_ERR_INVARIANT = -5
} bitmap_rank9_sel_c11_d58_err_t;



static inline const char* bitmap_rank9_sel_c11_d58_err_str(bitmap_rank9_sel_c11_d58_err_t err) {
    switch (err) {
        case BITMAP_RANK9_SEL_C11_D58_OK: return "ok";
        case BITMAP_RANK9_SEL_C11_D58_ERR_NULL: return "null pointer supplied";
        case BITMAP_RANK9_SEL_C11_D58_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BITMAP_RANK9_SEL_C11_D58_ERR_INVALID: return "domain precondition violated";
        case BITMAP_RANK9_SEL_C11_D58_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BITMAP_RANK9_SEL_C11_D58_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BITMAP_RANK9_SEL_C11_D58_ERRORS_H */
