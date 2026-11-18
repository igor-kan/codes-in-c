#ifndef TREAP_SPLIT_MERGE_C11_ERRORS_H
#define TREAP_SPLIT_MERGE_C11_ERRORS_H

typedef enum treap_split_merge_c11_err {
    TREAP_SPLIT_MERGE_C11_OK = 0,
    TREAP_SPLIT_MERGE_C11_ERR_NULL = -1,
    TREAP_SPLIT_MERGE_C11_ERR_BOUNDS = -2,
    TREAP_SPLIT_MERGE_C11_ERR_INVALID = -3,
    TREAP_SPLIT_MERGE_C11_ERR_OVERFLOW = -4,
    TREAP_SPLIT_MERGE_C11_ERR_INVARIANT = -5
} treap_split_merge_c11_err_t;



static inline const char* treap_split_merge_c11_err_str(treap_split_merge_c11_err_t err) {
    switch (err) {
        case TREAP_SPLIT_MERGE_C11_OK: return "ok";
        case TREAP_SPLIT_MERGE_C11_ERR_NULL: return "null pointer supplied";
        case TREAP_SPLIT_MERGE_C11_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case TREAP_SPLIT_MERGE_C11_ERR_INVALID: return "domain precondition violated";
        case TREAP_SPLIT_MERGE_C11_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case TREAP_SPLIT_MERGE_C11_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* TREAP_SPLIT_MERGE_C11_ERRORS_H */
