#ifndef SPLAY_TREE_INTRUSIVE_ERRORS_H
#define SPLAY_TREE_INTRUSIVE_ERRORS_H

typedef enum splay_tree_intrusive_err {
    SPLAY_TREE_INTRUSIVE_OK = 0,
    SPLAY_TREE_INTRUSIVE_ERR_NULL = -1,
    SPLAY_TREE_INTRUSIVE_ERR_BOUNDS = -2,
    SPLAY_TREE_INTRUSIVE_ERR_INVALID = -3,
    SPLAY_TREE_INTRUSIVE_ERR_OVERFLOW = -4,
    SPLAY_TREE_INTRUSIVE_ERR_INVARIANT = -5
} splay_tree_intrusive_err_t;



static inline const char* splay_tree_intrusive_err_str(splay_tree_intrusive_err_t err) {
    switch (err) {
        case SPLAY_TREE_INTRUSIVE_OK: return "ok";
        case SPLAY_TREE_INTRUSIVE_ERR_NULL: return "null pointer supplied";
        case SPLAY_TREE_INTRUSIVE_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case SPLAY_TREE_INTRUSIVE_ERR_INVALID: return "domain precondition violated";
        case SPLAY_TREE_INTRUSIVE_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case SPLAY_TREE_INTRUSIVE_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* SPLAY_TREE_INTRUSIVE_ERRORS_H */
