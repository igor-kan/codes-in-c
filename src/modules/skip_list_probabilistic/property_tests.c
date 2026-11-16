#include "interface.h"
#include <assert.h>

int main(void) {
    skiplist_t sl;
    sl_init(&sl, 999U);
    int64_t keys[120], out[120];
    for (int i = 0; i < 120; ++i) {
        int64_t k = (i * 37) % 211;
        sl_insert(&sl, k, k * 2 + 1);
        keys[i] = k;
    }
    assert(sl_verify_invariants(&sl) == SKIP_LIST_PROBABILISTIC_OK);
    assert(sl_batch_search_mt(&sl, keys, out, 120, 4) == SKIP_LIST_PROBABILISTIC_OK);
    for (int i = 0; i < 120; ++i) assert(out[i] == keys[i] * 2 + 1);
    sl_destroy(&sl);
    return 0;
}
