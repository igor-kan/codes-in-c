#include "interface.h"

zkw_bottom_up_segtree_c_err_t zkw_bottom_up_segtree_c_verify_guard(bool cond) {
    if (!cond) {
        return ZKW_BOTTOM_UP_SEGTREE_C_ERR_INVARIANT;
    }
    return ZKW_BOTTOM_UP_SEGTREE_C_OK;
}
