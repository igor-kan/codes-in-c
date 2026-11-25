#include "interface.h"

buddy_alloc_order_d60_err_t buddy_alloc_order_d60_validate_len(size_t n) {
    if (n == 0) {
        return BUDDY_ALLOC_ORDER_D60_ERR_INVALID;
    }
    return BUDDY_ALLOC_ORDER_D60_OK;
}
