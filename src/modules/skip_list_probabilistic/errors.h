#ifndef SKIP_LIST_PROBABILISTIC_ERRORS_H
#define SKIP_LIST_PROBABILISTIC_ERRORS_H

typedef enum skip_list_probabilistic_err {
    SKIP_LIST_PROBABILISTIC_OK = 0,
    SKIP_LIST_PROBABILISTIC_ERR_NULL = -1,
    SKIP_LIST_PROBABILISTIC_ERR_BOUNDS = -2,
    SKIP_LIST_PROBABILISTIC_ERR_INVALID = -3,
    SKIP_LIST_PROBABILISTIC_ERR_OVERFLOW = -4,
    SKIP_LIST_PROBABILISTIC_ERR_INVARIANT = -5
} skip_list_probabilistic_err_t;



static inline const char* skip_list_probabilistic_err_str(skip_list_probabilistic_err_t err) {
    switch (err) {
        case SKIP_LIST_PROBABILISTIC_OK: return "ok";
        case SKIP_LIST_PROBABILISTIC_ERR_NULL: return "null pointer supplied";
        case SKIP_LIST_PROBABILISTIC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SKIP_LIST_PROBABILISTIC_ERR_INVALID: return "domain precondition violated";
        case SKIP_LIST_PROBABILISTIC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SKIP_LIST_PROBABILISTIC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SKIP_LIST_PROBABILISTIC_ERRORS_H */
