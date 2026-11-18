#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(treap_split_merge_c11_validate_len(1) == TREAP_SPLIT_MERGE_C11_OK);
    treap_arena_t tr; treap_c_init(&tr);
    for (int i = 1; i <= 5; ++i) tr.root = treap_c_merge(&tr, tr.root, treap_c_new(&tr, i * 10, (uint32_t)(i * 2654435761u)));
    int32_t a = -1, b = -1;
    treap_c_split(&tr, tr.root, 2, &a, &b);
    assert(tr.pool[a].sum == 30 && tr.pool[b].sum == 120);
    tr.root = treap_c_merge(&tr, a, b);
    assert(tr.pool[tr.root].sum == 150);
    assert(treap_split_merge_c11_verify_guard(true) == TREAP_SPLIT_MERGE_C11_OK);
    return 0;
}
