#ifndef BUDDY_ALLOC_ORDER_D60_ERRORS_H
#define BUDDY_ALLOC_ORDER_D60_ERRORS_H

typedef enum buddy_alloc_order_d60_err {
    BUDDY_ALLOC_ORDER_D60_OK = 0,
    BUDDY_ALLOC_ORDER_D60_ERR_NULL = -1,
    BUDDY_ALLOC_ORDER_D60_ERR_BOUNDS = -2,
    BUDDY_ALLOC_ORDER_D60_ERR_INVALID = -3,
    BUDDY_ALLOC_ORDER_D60_ERR_OVERFLOW = -4,
    BUDDY_ALLOC_ORDER_D60_ERR_INVARIANT = -5
} buddy_alloc_order_d60_err_t;



static inline const char* buddy_alloc_order_d60_err_str(buddy_alloc_order_d60_err_t err) {
    switch (err) {
        case BUDDY_ALLOC_ORDER_D60_OK: return "ok";
        case BUDDY_ALLOC_ORDER_D60_ERR_NULL: return "null pointer supplied";
        case BUDDY_ALLOC_ORDER_D60_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case BUDDY_ALLOC_ORDER_D60_ERR_INVALID: return "domain precondition violated";
        case BUDDY_ALLOC_ORDER_D60_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case BUDDY_ALLOC_ORDER_D60_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* BUDDY_ALLOC_ORDER_D60_ERRORS_H */
