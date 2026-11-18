#include "interface.h"
#include <math.h>
#include <string.h>

static int32_t bh_link(binom_heap_t* h, int32_t a, int32_t b) {
    if (h->pool[a].key > h->pool[b].key) { int32_t t = a; a = b; b = t; }
    h->pool[b].sibling = h->pool[a].child;
    h->pool[a].child = b;
    h->pool[a].deg += 1;
    return a;
}
static void bh_carry_insert(binom_heap_t* h, int32_t root) {
    int32_t d = h->pool[root].deg;
    while (h->trees[d] != -1) {
        int32_t other = h->trees[d];
        h->trees[d] = -1;
        root = bh_link(h, root, other);
        ++d;
    }
    h->trees[d] = root;
}
void bh_init(binom_heap_t* h) {
    h->used = 0; h->count = 0;
    for (int i = 0; i < 12; ++i) h->trees[i] = -1;
}
void bh_push(binom_heap_t* h, int64_t key) {
    int32_t id = h->used++;
    h->pool[id] = (bnode_t){key, -1, -1, 0};
    bh_carry_insert(h, id);
    h->count += 1;
}
int64_t bh_pop_min(binom_heap_t* h) {
    int best_d = -1;
    for (int d = 0; d < 12; ++d) {
        if (h->trees[d] != -1 && (best_d == -1 || h->pool[h->trees[d]].key < h->pool[h->trees[best_d]].key)) best_d = d;
    }
    int32_t root = h->trees[best_d];
    h->trees[best_d] = -1;
    int64_t ans = h->pool[root].key;
    int32_t kids[12]; int nk = 0;
    for (int32_t c = h->pool[root].child; c != -1; c = h->pool[c].sibling) kids[nk++] = c;
    for (int i = nk - 1; i >= 0; --i) {
        h->pool[kids[i]].sibling = -1;
        bh_carry_insert(h, kids[i]);
    }
    h->count -= 1;
    return ans;
}
