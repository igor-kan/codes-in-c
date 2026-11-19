#include "interface.h"

zkw_bottom_up_segtree_c_err_t zkw_bottom_up_segtree_c_validate_len(size_t n) {
    if (n == 0) {
        return ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVALID;
    }
    return ZKW_BOTTOM_UP_SEGTREE_C_OK;
}
