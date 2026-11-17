#include "interface.h"
#include <assert.h>

int main(void) {
    splay_tree_t t;
    splay_init(&t);
    for (int i = 10; i >= 1; --i) assert(splay_insert(&t, i * 3, i) == SPLAY_TREE_INTRUSIVE_OK);
    assert(splay_verify_bst(&t) == SPLAY_TREE_INTRUSIVE_OK);
    int64_t v = 0;
    assert(splay_find(&t, 15, &v) && v == 5);
    assert(splay_erase(&t, 15));
    assert(!splay_find(&t, 15, &v));
    assert(splay_verify_bst(&t) == SPLAY_TREE_INTRUSIVE_OK);
    return 0;
}
