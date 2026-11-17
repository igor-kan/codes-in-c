#ifndef RED_BLACK_TREE_C11_ERRORS_H
#define RED_BLACK_TREE_C11_ERRORS_H

typedef enum red_black_tree_c11_err {
    RED_BLACK_TREE_C11_OK = 0,
    RED_BLACK_TREE_C11_ERR_NULL = -1,
    RED_BLACK_TREE_C11_ERR_BOUNDS = -2,
    RED_BLACK_TREE_C11_ERR_INVALID = -3,
    RED_BLACK_TREE_C11_ERR_OVERFLOW = -4,
    RED_BLACK_TREE_C11_ERR_INVARIANT = -5
} red_black_tree_c11_err_t;



static inline const char* red_black_tree_c11_err_str(red_black_tree_c11_err_t err) {
    switch (err) {
        case RED_BLACK_TREE_C11_OK: return "ok";
        case RED_BLACK_TREE_C11_ERR_NULL: return "null pointer supplied";
        case RED_BLACK_TREE_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RED_BLACK_TREE_C11_ERR_INVALID: return "domain precondition violated";
        case RED_BLACK_TREE_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RED_BLACK_TREE_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RED_BLACK_TREE_C11_ERRORS_H */
