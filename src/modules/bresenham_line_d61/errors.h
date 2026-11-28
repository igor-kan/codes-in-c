#ifndef BRESENHAM_LINE_D61_ERRORS_H
#define BRESENHAM_LINE_D61_ERRORS_H

typedef enum bresenham_line_d61_err {
    BRESENHAM_LINE_D61_OK = 0,
    BRESENHAM_LINE_D61_ERR_NULL = -1,
    BRESENHAM_LINE_D61_ERR_BOUNDS = -2,
    BRESENHAM_LINE_D61_ERR_INVALID = -3,
    BRESENHAM_LINE_D61_ERR_OVERFLOW = -4,
    BRESENHAM_LINE_D61_ERR_INVARIANT = -5
} bresenham_line_d61_err_t;



static inline const char* bresenham_line_d61_err_str(bresenham_line_d61_err_t err) {
    switch (err) {
        case BRESENHAM_LINE_D61_OK: return "ok";
        case BRESENHAM_LINE_D61_ERR_NULL: return "null pointer supplied";
        case BRESENHAM_LINE_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BRESENHAM_LINE_D61_ERR_INVALID: return "domain precondition violated";
        case BRESENHAM_LINE_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BRESENHAM_LINE_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BRESENHAM_LINE_D61_ERRORS_H */
