#include "interface.h"

treap_split_merge_c11_err_t treap_split_merge_c11_verify_guard(bool cond) {
    if (!cond) {
        return TREAP_SPLIT_MERGE_C11_ERR_INVARIANT;
    }
    return TREAP_SPLIT_MERGE_C11_OK;
}
