#include "interface.h"

skip_list_probabilistic_err_t sl_verify_invariants(const skiplist_t* sl) {
    if (sl_validate_state(sl) != SKIP_LIST_PROBABILISTIC_OK) return SKIP_LIST_PROBABILISTIC_ERR_INVARIANT;
    size_t seen = 0;
    const sl_node_t* cur = sl->head->next[0];
    const sl_node_t* prev = NULL;
    while (cur) {
        if (prev && prev->key >= cur->key) return SKIP_LIST_PROBABILISTIC_ERR_INVARIANT;
        prev = cur;
        cur = cur->next[0];
        ++seen;
    }
    if (seen != sl->count) return SKIP_LIST_PROBABILISTIC_ERR_INVARIANT;
    return SKIP_LIST_PROBABILISTIC_OK;
}
