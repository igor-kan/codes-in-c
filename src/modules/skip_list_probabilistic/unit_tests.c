#include "interface.h"
#include <assert.h>

int main(void) {
    skiplist_t sl;
    assert(sl_init(&sl, 42U) == SKIP_LIST_PROBABILISTIC_OK);
    for (int64_t k = 20; k >= 1; --k) assert(sl_insert(&sl, k * 3, k * 10) == SKIP_LIST_PROBABILISTIC_OK);
    int64_t val = 0;
    assert(sl_find(&sl, 21, &val) && val == 70);
    assert(sl_insert(&sl, 21, 777) == SKIP_LIST_PROBABILISTIC_OK);
    assert(sl_find(&sl, 21, &val) && val == 777);
    assert(sl_delete(&sl, 15));
    assert(!sl_find(&sl, 15, &val));
    assert(sl_verify_invariants(&sl) == SKIP_LIST_PROBABILISTIC_OK);
    sl_destroy(&sl);
    return 0;
}
