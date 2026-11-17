#include "interface.h"
#include <assert.h>

int main(void) {
    llrb_tree_t t;
    llrb_init(&t);
    for (int i = 0; i < 64; ++i) assert(llrb_put(&t, i * 2, i + 100) == RED_BLACK_TREE_C11_OK);
    assert(llrb_verify_properties(&t) == RED_BLACK_TREE_C11_OK);
    int64_t v = 0;
    assert(llrb_get(&t, 42, &v) && v == 121);
    assert(!llrb_get(&t, 43, &v));
    assert(llrb_fast_rank(&t, 10) == 5);
    return 0;
}
