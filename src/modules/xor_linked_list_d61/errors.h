#ifndef XOR_LINKED_LIST_D61_ERRORS_H
#define XOR_LINKED_LIST_D61_ERRORS_H

typedef enum xor_linked_list_d61_err {
    XOR_LINKED_LIST_D61_OK = 0,
    XOR_LINKED_LIST_D61_ERR_NULL = -1,
    XOR_LINKED_LIST_D61_ERR_BOUNDS = -2,
    XOR_LINKED_LIST_D61_ERR_INVALID = -3,
    XOR_LINKED_LIST_D61_ERR_OVERFLOW = -4,
    XOR_LINKED_LIST_D61_ERR_INVARIANT = -5
} xor_linked_list_d61_err_t;



static inline const char* xor_linked_list_d61_err_str(xor_linked_list_d61_err_t err) {
    switch (err) {
        case XOR_LINKED_LIST_D61_OK: return "ok";
        case XOR_LINKED_LIST_D61_ERR_NULL: return "null pointer supplied";
        case XOR_LINKED_LIST_D61_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case XOR_LINKED_LIST_D61_ERR_INVALID: return "domain precondition violated";
        case XOR_LINKED_LIST_D61_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case XOR_LINKED_LIST_D61_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* XOR_LINKED_LIST_D61_ERRORS_H */
