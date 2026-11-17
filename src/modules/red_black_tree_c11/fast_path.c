#include "interface.h"

static int32_t count_lt(const llrb_tree_t* t, int32_t h, int64_t key) {
    if (h < 0) return 0;
    if (t->nodes[h].key < key) return 1 + count_lt(t, t->nodes[h].left, key) + count_lt(t, t->nodes[h].right, key);
    return count_lt(t, t->nodes[h].left, key);
}

int32_t llrb_fast_rank(const llrb_tree_t* t, int64_t key) {
    return count_lt(t, t->root, key);
}
