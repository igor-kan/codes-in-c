#include "interface.h"

static bool is_red(const llrb_tree_t* t, int32_t h) {
    return h >= 0 && t->nodes[h].red;
}

static int32_t rot_left(llrb_tree_t* t, int32_t h) {
    int32_t x = t->nodes[h].right;
    t->nodes[h].right = t->nodes[x].left;
    t->nodes[x].left = h;
    t->nodes[x].red = t->nodes[h].red;
    t->nodes[h].red = true;
    return x;
}

static int32_t rot_right(llrb_tree_t* t, int32_t h) {
    int32_t x = t->nodes[h].left;
    t->nodes[h].left = t->nodes[x].right;
    t->nodes[x].right = h;
    t->nodes[x].red = t->nodes[h].red;
    t->nodes[h].red = true;
    return x;
}

static void flip_colors(llrb_tree_t* t, int32_t h) {
    t->nodes[h].red = true;
    t->nodes[t->nodes[h].left].red = false;
    t->nodes[t->nodes[h].right].red = false;
}

static int32_t put_rec(llrb_tree_t* t, int32_t h, int64_t key, int64_t val, bool* oom) {
    if (h < 0) {
        if (t->cap >= LLRB_MAX) { *oom = true; return -1; }
        int32_t id = t->cap++;
        t->nodes[id] = (llrb_node_t){key, val, -1, -1, true};
        return id;
    }
    if (key < t->nodes[h].key) t->nodes[h].left = put_rec(t, t->nodes[h].left, key, val, oom);
    else if (key > t->nodes[h].key) t->nodes[h].right = put_rec(t, t->nodes[h].right, key, val, oom);
    else t->nodes[h].val = val;

    if (is_red(t, t->nodes[h].right) && !is_red(t, t->nodes[h].left)) h = rot_left(t, h);
    if (is_red(t, t->nodes[h].left) && is_red(t, t->nodes[t->nodes[h].left].left)) h = rot_right(t, h);
    if (is_red(t, t->nodes[h].left) && is_red(t, t->nodes[h].right)) flip_colors(t, h);
    return h;
}

void llrb_init(llrb_tree_t* t) {
    t->root = -1;
    t->cap = 0;
}

red_black_tree_c11_err_t llrb_put(llrb_tree_t* t, int64_t key, int64_t val) {
    if (!t) return RED_BLACK_TREE_C11_ERR_NULL;
    bool oom = false;
    t->root = put_rec(t, t->root, key, val, &oom);
    if (t->root >= 0) t->nodes[t->root].red = false;
    return oom ? RED_BLACK_TREE_C11_ERR_BOUNDS : RED_BLACK_TREE_C11_OK;
}

bool llrb_get(const llrb_tree_t* t, int64_t key, int64_t* out_val) {
    int32_t cur = t->root;
    while (cur >= 0) {
        if (key < t->nodes[cur].key) cur = t->nodes[cur].left;
        else if (key > t->nodes[cur].key) cur = t->nodes[cur].right;
        else {
            if (out_val) *out_val = t->nodes[cur].val;
            return true;
        }
    }
    return false;
}
