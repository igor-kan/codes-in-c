#ifndef STOER_WAGNER_MINCUT_C11_ERRORS_H
#define STOER_WAGNER_MINCUT_C11_ERRORS_H

typedef enum stoer_wagner_mincut_c11_err {
    STOER_WAGNER_MINCUT_C11_OK = 0,
    STOER_WAGNER_MINCUT_C11_ERR_NULL = -1,
    STOER_WAGNER_MINCUT_C11_ERR_BOUNDS = -2,
    STOER_WAGNER_MINCUT_C11_ERR_INVALID = -3,
    STOER_WAGNER_MINCUT_C11_ERR_OVERFLOW = -4,
    STOER_WAGNER_MINCUT_C11_ERR_INVARIANT = -5
} stoer_wagner_mincut_c11_err_t;



static inline const char* stoer_wagner_mincut_c11_err_str(stoer_wagner_mincut_c11_err_t err) {
    switch (err) {
        case STOER_WAGNER_MINCUT_C11_OK: return "ok";
        case STOER_WAGNER_MINCUT_C11_ERR_NULL: return "null pointer supplied";
        case STOER_WAGNER_MINCUT_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case STOER_WAGNER_MINCUT_C11_ERR_INVALID: return "domain precondition violated";
        case STOER_WAGNER_MINCUT_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case STOER_WAGNER_MINCUT_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* STOER_WAGNER_MINCUT_C11_ERRORS_H */
