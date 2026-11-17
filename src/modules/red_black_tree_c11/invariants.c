#include "interface.h"

static int32_t check_bh(const llrb_tree_t* t, int32_t h) {
    if (h < 0) return 1;
    if (t->nodes[h].right >= 0 && t->nodes[t->nodes[h].right].red) return -1;
    if (t->nodes[h].red && t->nodes[h].left >= 0 && t->nodes[t->nodes[h].left].red) return -1;
    int32_t lb = check_bh(t, t->nodes[h].left);
    int32_t rb = check_bh(t, t->nodes[h].right);
    if (lb < 0 || rb < 0 || lb != rb) return -1;
    return lb + (t->nodes[h].red ? 0 : 1);
}

red_black_tree_c11_err_t llrb_verify_properties(const llrb_tree_t* t) {
    if (!t) return RED_BLACK_TREE_C11_ERR_NULL;
    if (t->root >= 0 && t->nodes[t->root].red) return RED_BLACK_TREE_C11_ERR_INVARIANT;
    return check_bh(t, t->root) > 0 ? RED_BLACK_TREE_C11_OK : RED_BLACK_TREE_C11_ERR_INVARIANT;
}
