#ifndef FENWICK_2D_GRID_C11_ERRORS_H
#define FENWICK_2D_GRID_C11_ERRORS_H

typedef enum fenwick_2d_grid_c11_err {
    FENWICK_2D_GRID_C11_OK = 0,
    FENWICK_2D_GRID_C11_ERR_NULL = -1,
    FENWICK_2D_GRID_C11_ERR_BOUNDS = -2,
    FENWICK_2D_GRID_C11_ERR_INVALID = -3,
    FENWICK_2D_GRID_C11_ERR_OVERFLOW = -4,
    FENWICK_2D_GRID_C11_ERR_INVARIANT = -5
} fenwick_2d_grid_c11_err_t;



static inline const char* fenwick_2d_grid_c11_err_str(fenwick_2d_grid_c11_err_t err) {
    switch (err) {
        case FENWICK_2D_GRID_C11_OK: return "ok";
        case FENWICK_2D_GRID_C11_ERR_NULL: return "null pointer supplied";
        case FENWICK_2D_GRID_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case FENWICK_2D_GRID_C11_ERR_INVALID: return "domain precondition violated";
        case FENWICK_2D_GRID_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case FENWICK_2D_GRID_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* FENWICK_2D_GRID_C11_ERRORS_H */
