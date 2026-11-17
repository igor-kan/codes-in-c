#include "interface.h"

static int64_t sum_dfs(const splay_tree_t* t, int32_t u, int64_t lo, int64_t hi) {
    if (u < 0) return 0;
    int64_t s = 0;
    int64_t k = t->nodes[u].key;
    if (k > lo) s += sum_dfs(t, t->nodes[u].ch[0], lo, hi);
    if (k >= lo && k <= hi) s += t->nodes[u].val;
    if (k < hi) s += sum_dfs(t, t->nodes[u].ch[1], lo, hi);
    return s;
}

int64_t splay_fast_range_sum(splay_tree_t* t, int64_t lo, int64_t hi) {
    return sum_dfs(t, t->root, lo, hi);
}
