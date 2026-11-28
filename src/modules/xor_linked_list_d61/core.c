#include "interface.h"
#include <math.h>
#include <string.h>

void xor_list_init(xor_list_t* l) {
    l->used = 0;
    l->head = 0;
    l->tail = 0;
}
size_t xor_list_size(const xor_list_t* l) {
    return l->used;
}
size_t xor_list_push_back(xor_list_t* l, int64_t v) {
    if (l->used >= (size_t)XOR_LIST_CAP) return 0;
    uintptr_t addr = (uintptr_t)&l->pool[l->used];
    xor_node_t* nd = &l->pool[l->used];
    l->used += 1;
    nd->val = v;
    nd->both = l->tail;
    if (l->tail != 0) {
        xor_node_t* prev = (xor_node_t*)l->tail;
        prev->both = prev->both ^ addr;
    } else {
        l->head = addr;
    }
    l->tail = addr;
    return 1;
}
size_t xor_list_forward(const xor_list_t* l, int64_t* out, size_t cap) {
    uintptr_t prev = 0;
    uintptr_t cur = l->head;
    size_t count = 0;
    while (cur != 0 && count < cap) {
        const xor_node_t* nd = (const xor_node_t*)cur;
        out[count++] = nd->val;
        uintptr_t next = nd->both ^ prev;
        prev = cur;
        cur = next;
    }
    return count;
}
