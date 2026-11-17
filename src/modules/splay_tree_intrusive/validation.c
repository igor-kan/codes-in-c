#include "interface.h"

splay_tree_intrusive_err_t splay_validate_tree(const splay_tree_t* t) {
    if (!t) return SPLAY_TREE_INTRUSIVE_ERR_NULL;
    if (t->cap > SPLAY_MAX || t->count < 0) return SPLAY_TREE_INTRUSIVE_ERR_BOUNDS;
    return SPLAY_TREE_INTRUSIVE_OK;
}
