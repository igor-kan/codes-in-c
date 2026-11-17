#include "interface.h"

static int32_t ph_meld(pairing_heap_t* h, int32_t a, int32_t b) {
    if (a < 0) return b;
    if (b < 0) return a;
    if (h->nodes[a].key > h->nodes[b].key) {
        int32_t tmp = a;
        a = b;
        b = tmp;
    }
    h->nodes[b].prev = a;
    h->nodes[b].sibling = h->nodes[a].child;
    if (h->nodes[a].child >= 0) h->nodes[h->nodes[a].child].prev = b;
    h->nodes[a].child = b;
    h->nodes[a].prev = -1;
    h->nodes[a].sibling = -1;
    return a;
}

static int32_t ph_two_pass(pairing_heap_t* h, int32_t first) {
    int32_t pairs[PH_MAX_NODES];
    int32_t np = 0;
    int32_t cur = first;
    while (cur >= 0) {
        int32_t a = cur;
        int32_t b = h->nodes[a].sibling;
        int32_t nxt = (b >= 0) ? h->nodes[b].sibling : -1;
        h->nodes[a].sibling = -1;
        h->nodes[a].prev = -1;
        if (b >= 0) {
            h->nodes[b].sibling = -1;
            h->nodes[b].prev = -1;
            pairs[np++] = ph_meld(h, a, b);
        } else {
            pairs[np++] = a;
        }
        cur = nxt;
    }
    int32_t acc = -1;
    for (int32_t i = np - 1; i >= 0; --i) acc = ph_meld(h, acc, pairs[i]);
    return acc;
}

pairing_heap_c11_err_t ph_init(pairing_heap_t* h) {
    if (!h) return PAIRING_HEAP_C11_ERR_NULL;
    h->size = 0;
    h->cap = 0;
    h->root = -1;
    return PAIRING_HEAP_C11_OK;
}

pairing_heap_c11_err_t ph_push(pairing_heap_t* h, int64_t key, int32_t val, int32_t* out_id) {
    if (!h) return PAIRING_HEAP_C11_ERR_NULL;
    if (h->cap >= PH_MAX_NODES) return PAIRING_HEAP_C11_ERR_BOUNDS;
    int32_t id = h->cap++;
    h->nodes[id] = (ph_node_t){key, val, -1, -1, -1, true};
    h->root = ph_meld(h, h->root, id);
    h->size++;
    if (out_id) *out_id = id;
    return PAIRING_HEAP_C11_OK;
}

pairing_heap_c11_err_t ph_decrease_key(pairing_heap_t* h, int32_t id, int64_t new_key) {
    pairing_heap_c11_err_t err = ph_validate_handle(h, id);
    if (err != PAIRING_HEAP_C11_OK) return err;
    if (new_key > h->nodes[id].key) return PAIRING_HEAP_C11_ERR_INVALID;
    h->nodes[id].key = new_key;
    if (id == h->root) return PAIRING_HEAP_C11_OK;
    int32_t p = h->nodes[id].prev;
    if (h->nodes[p].child == id) h->nodes[p].child = h->nodes[id].sibling;
    else h->nodes[p].sibling = h->nodes[id].sibling;
    if (h->nodes[id].sibling >= 0) h->nodes[h->nodes[id].sibling].prev = p;
    h->nodes[id].prev = -1;
    h->nodes[id].sibling = -1;
    h->root = ph_meld(h, h->root, id);
    return PAIRING_HEAP_C11_OK;
}

pairing_heap_c11_err_t ph_pop_min(pairing_heap_t* h, int64_t* out_key, int32_t* out_val) {
    if (!h) return PAIRING_HEAP_C11_ERR_NULL;
    if (h->root < 0) return PAIRING_HEAP_C11_ERR_BOUNDS;
    int32_t old = h->root;
    if (out_key) *out_key = h->nodes[old].key;
    if (out_val) *out_val = h->nodes[old].value;
    h->nodes[old].active = false;
    int32_t child = h->nodes[old].child;
    h->nodes[old].child = -1;
    h->root = ph_two_pass(h, child);
    h->size--;
    return PAIRING_HEAP_C11_OK;
}
