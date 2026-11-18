#include "interface.h"

treap_split_merge_c11_err_t treap_split_merge_c11_validate_len(size_t n) {
    if (n == 0) {
        return TREAP_SPLIT_MERGE_C11_ERR_INVALID;
    }
    return TREAP_SPLIT_MERGE_C11_OK;
}
