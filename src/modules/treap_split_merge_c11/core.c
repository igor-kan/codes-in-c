#include "interface.h"
#include <math.h>
#include <string.h>

static int32_t treap_sz(const treap_arena_t* t, int32_t u) { return u < 0 ? 0 : t->pool[u].sz; }
static int64_t treap_sm(const treap_arena_t* t, int32_t u) { return u < 0 ? 0 : t->pool[u].sum; }
static void treap_pull(treap_arena_t* t, int32_t u) {
    if (u < 0) return;
    t->pool[u].sz = 1 + treap_sz(t, t->pool[u].l) + treap_sz(t, t->pool[u].r);
    t->pool[u].sum = t->pool[u].val + treap_sm(t, t->pool[u].l) + treap_sm(t, t->pool[u].r);
}
void treap_c_init(treap_arena_t* t) { t->used = 0; t->root = -1; }
int32_t treap_c_new(treap_arena_t* t, int64_t val, uint32_t prio) {
    int32_t id = t->used++;
    t->pool[id] = (treap_node_c_t){val, val, prio, 1, -1, -1};
    return id;
}
void treap_c_split(treap_arena_t* t, int32_t u, int32_t k, int32_t* out_l, int32_t* out_r) {
    if (u < 0) { *out_l = -1; *out_r = -1; return; }
    int32_t lsz = treap_sz(t, t->pool[u].l);
    if (k <= lsz) {
        treap_c_split(t, t->pool[u].l, k, out_l, &t->pool[u].l);
        *out_r = u;
    } else {
        treap_c_split(t, t->pool[u].r, k - lsz - 1, &t->pool[u].r, out_r);
        *out_l = u;
    }
    treap_pull(t, u);
}
int32_t treap_c_merge(treap_arena_t* t, int32_t a, int32_t b) {
    if (a < 0) return b;
    if (b < 0) return a;
    if (t->pool[a].prio > t->pool[b].prio) {
        t->pool[a].r = treap_c_merge(t, t->pool[a].r, b);
        treap_pull(t, a);
        return a;
    }
    t->pool[b].l = treap_c_merge(t, a, t->pool[b].l);
    treap_pull(t, b);
    return b;
}
