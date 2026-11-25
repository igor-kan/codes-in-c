#include "interface.h"
#include <math.h>
#include <string.h>

void buddy_init_d60(buddy_pool_t* bp) {
    memset(bp->used, 0, sizeof(bp->used));
}
static int buddy_node(int offset, int order) {
    int level = BUDDY_MAX_ORDER - order;
    return (1 << level) + (offset >> order);
}
static bool has_used_descendant(const buddy_pool_t* bp, int node) {
    if (node >= (int)sizeof(bp->used)) return false;
    if (bp->used[node]) return true;
    return has_used_descendant(bp, node * 2) || has_used_descendant(bp, node * 2 + 1);
}
static bool has_used_ancestor(const buddy_pool_t* bp, int node) {
    for (int cur = node; cur >= 1; cur >>= 1) {
        if (bp->used[cur]) return true;
    }
    return false;
}
int buddy_alloc_d60(buddy_pool_t* bp, int order) {
    if (order < 0 || order > BUDDY_MAX_ORDER) return -1;
    int step = 1 << order;
    for (int off = 0; off < (int)BUDDY_LEAVES; off += step) {
        int nd = buddy_node(off, order);
        if (!has_used_ancestor(bp, nd) && !has_used_descendant(bp, nd)) {
            bp->used[nd] = 1;
            return off;
        }
    }
    return -1;
}
void buddy_free_d60(buddy_pool_t* bp, int offset, int order) {
    if (order < 0 || order > BUDDY_MAX_ORDER) return;
    int nd = buddy_node(offset, order);
    bp->used[nd] = 0;
}
