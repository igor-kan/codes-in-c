#ifndef SHELL_SORT_CIURA_D61_ERRORS_H
#define SHELL_SORT_CIURA_D61_ERRORS_H

typedef enum shell_sort_ciura_d61_err {
    SHELL_SORT_CIURA_D61_OK = 0,
    SHELL_SORT_CIURA_D61_ERR_NULL = -1,
    SHELL_SORT_CIURA_D61_ERR_BOUNDS = -2,
    SHELL_SORT_CIURA_D61_ERR_INVALID = -3,
    SHELL_SORT_CIURA_D61_ERR_OVERFLOW = -4,
    SHELL_SORT_CIURA_D61_ERR_INVARIANT = -5
} shell_sort_ciura_d61_err_t;



static inline const char* shell_sort_ciura_d61_err_str(shell_sort_ciura_d61_err_t err) {
    switch (err) {
        case SHELL_SORT_CIURA_D61_OK: return "ok";
        case SHELL_SORT_CIURA_D61_ERR_NULL: return "null pointer supplied";
        case SHELL_SORT_CIURA_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SHELL_SORT_CIURA_D61_ERR_INVALID: return "domain precondition violated";
        case SHELL_SORT_CIURA_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SHELL_SORT_CIURA_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SHELL_SORT_CIURA_D61_ERRORS_H */
