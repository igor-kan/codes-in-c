#include "interface.h"

static void splay_rotate(splay_tree_t* t, int32_t x) {
    int32_t p = t->nodes[x].parent;
    if (p < 0) return;
    int32_t g = t->nodes[p].parent;
    int dir = (t->nodes[p].ch[1] == x) ? 1 : 0;
    int32_t b = t->nodes[x].ch[dir ^ 1];
    if (g >= 0) {
        if (t->nodes[g].ch[0] == p) t->nodes[g].ch[0] = x;
        else t->nodes[g].ch[1] = x;
    } else {
        t->root = x;
    }
    t->nodes[x].parent = g;
    t->nodes[x].ch[dir ^ 1] = p;
    t->nodes[p].parent = x;
    t->nodes[p].ch[dir] = b;
    if (b >= 0) t->nodes[b].parent = p;
}

static void splay_up(splay_tree_t* t, int32_t x) {
    while (t->nodes[x].parent >= 0) {
        int32_t p = t->nodes[x].parent;
        int32_t g = t->nodes[p].parent;
        if (g >= 0) {
            bool zz = ((t->nodes[g].ch[0] == p) == (t->nodes[p].ch[0] == x));
            splay_rotate(t, zz ? p : x);
        }
        splay_rotate(t, x);
    }
}

void splay_init(splay_tree_t* t) {
    t->root = -1;
    t->cap = 0;
    t->count = 0;
}

splay_tree_intrusive_err_t splay_insert(splay_tree_t* t, int64_t key, int64_t val) {
    if (!t) return SPLAY_TREE_INTRUSIVE_ERR_NULL;
    int32_t cur = t->root, par = -1;
    while (cur >= 0) {
        par = cur;
        if (key == t->nodes[cur].key) {
            t->nodes[cur].val = val;
            splay_up(t, cur);
            return SPLAY_TREE_INTRUSIVE_OK;
        }
        cur = t->nodes[cur].ch[key > t->nodes[cur].key ? 1 : 0];
    }
    if (t->cap >= SPLAY_MAX) return SPLAY_TREE_INTRUSIVE_ERR_BOUNDS;
    int32_t id = t->cap++;
    t->nodes[id] = (splay_node_t){key, val, {-1, -1}, par, true};
    if (par < 0) t->root = id;
    else t->nodes[par].ch[key > t->nodes[par].key ? 1 : 0] = id;
    t->count++;
    splay_up(t, id);
    return SPLAY_TREE_INTRUSIVE_OK;
}

bool splay_find(splay_tree_t* t, int64_t key, int64_t* out_val) {
    int32_t cur = t->root, last = -1;
    while (cur >= 0) {
        last = cur;
        if (key == t->nodes[cur].key) {
            splay_up(t, cur);
            if (out_val) *out_val = t->nodes[cur].val;
            return true;
        }
        cur = t->nodes[cur].ch[key > t->nodes[cur].key ? 1 : 0];
    }
    if (last >= 0) splay_up(t, last);
    return false;
}

bool splay_erase(splay_tree_t* t, int64_t key) {
    if (!splay_find(t, key, NULL)) return false;
    int32_t z = t->root;
    int32_t l = t->nodes[z].ch[0];
    int32_t r = t->nodes[z].ch[1];
    t->nodes[z].active = false;
    t->count--;
    if (l < 0) {
        t->root = r;
        if (r >= 0) t->nodes[r].parent = -1;
    } else {
        t->nodes[l].parent = -1;
        t->root = l;
        int32_t m = l;
        while (t->nodes[m].ch[1] >= 0) m = t->nodes[m].ch[1];
        splay_up(t, m);
        t->nodes[m].ch[1] = r;
        if (r >= 0) t->nodes[r].parent = m;
    }
    return true;
}
