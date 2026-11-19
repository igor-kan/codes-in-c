#ifndef ZKW_BOTTOM_UP_SEGTREE_C_ERRORS_H
#define ZKW_BOTTOM_UP_SEGTREE_C_ERRORS_H

typedef enum zkw_bottom_up_segtree_c_err {
    ZKW_BOTTOM_UP_SEGTREE_C_OK = 0,
    ZKW_BOTTOM_UP_SEGTREE_C_ERR_NULL = -1,
    ZKW_BOTTOM_UP_SEGTREE_C_ERR_BOUNDS = -2,
    ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVALID = -3,
    ZKW_BOTTOM_UP_SEGTREE_C_ERR_OVERFLOW = -4,
    ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVARIANT = -5
} zkw_bottom_up_segtree_c_err_t;



static inline const char* zkw_bottom_up_segtree_c_err_str(zkw_bottom_up_segtree_c_err_t err) {
    switch (err) {
        case ZKW_BOTTOM_UP_SEGTREE_C_OK: return "ok";
        case ZKW_BOTTOM_UP_SEGTREE_C_ERR_NULL: return "null pointer supplied";
        case ZKW_BOTTOM_UP_SEGTREE_C_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVALID: return "domain precondition violated";
        case ZKW_BOTTOM_UP_SEGTREE_C_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* ZKW_BOTTOM_UP_SEGTREE_C_ERRORS_H */
