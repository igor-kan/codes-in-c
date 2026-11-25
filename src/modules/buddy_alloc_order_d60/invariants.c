#include "interface.h"

buddy_alloc_order_d60_err_t buddy_alloc_order_d60_verify_guard(bool cond) {
    if (!cond) {
        return BUDDY_ALLOC_ORDER_D60_ERR_INVARIANT;
    }
    return BUDDY_ALLOC_ORDER_D60_OK;
}
