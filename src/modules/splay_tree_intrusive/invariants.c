#include "interface.h"

static bool check_order(const splay_tree_t* t, int32_t u, int64_t* prev, bool* has_prev) {
    if (u < 0) return true;
    if (!check_order(t, t->nodes[u].ch[0], prev, has_prev)) return false;
    if (*has_prev && t->nodes[u].key <= *prev) return false;
    *prev = t->nodes[u].key;
    *has_prev = true;
    return check_order(t, t->nodes[u].ch[1], prev, has_prev);
}

splay_tree_intrusive_err_t splay_verify_bst(const splay_tree_t* t) {
    if (!t) return SPLAY_TREE_INTRUSIVE_ERR_NULL;
    int64_t prev = 0;
    bool has = false;
    return check_order(t, t->root, &prev, &has) ? SPLAY_TREE_INTRUSIVE_OK : SPLAY_TREE_INTRUSIVE_ERR_INVARIANT;
}
