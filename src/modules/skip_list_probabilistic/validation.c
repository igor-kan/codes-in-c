#include "interface.h"

skip_list_probabilistic_err_t sl_validate_state(const skiplist_t* sl) {
    if (!sl || !sl->head) return SKIP_LIST_PROBABILISTIC_ERR_NULL;
    if (sl->max_level < 1 || sl->max_level > SKIPLIST_MAX_LEVEL) return SKIP_LIST_PROBABILISTIC_ERR_BOUNDS;
    return SKIP_LIST_PROBABILISTIC_OK;
}
