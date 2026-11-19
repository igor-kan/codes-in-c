#include "interface.h"

fenwick_order_stat_c11_err_t fenwick_order_stat_c11_validate_len(size_t n) {
    if (n == 0) {
        return FENWICK_ORDER_STAT_C11_ERR_INVALID;
    }
    return FENWICK_ORDER_STAT_C11_OK;
}
