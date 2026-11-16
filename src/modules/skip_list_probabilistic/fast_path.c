#include "interface.h"

size_t sl_count_range(const skiplist_t* sl, int64_t lo, int64_t hi) {
    if (!sl || !sl->head || lo > hi) return 0;
    const sl_node_t* x = sl->head;
    for (int i = sl->max_level - 1; i >= 0; --i) {
        while (x->next[i] && x->next[i]->key < lo) x = x->next[i];
    }
    x = x->next[0];
    size_t cnt = 0;
    while (x && x->key <= hi) { ++cnt; x = x->next[0]; }
    return cnt;
}
