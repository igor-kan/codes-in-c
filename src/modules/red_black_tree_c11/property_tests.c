#include "interface.h"
#include <assert.h>

int main(void) {
    llrb_tree_t t;
    llrb_init(&t);
    int64_t probes[64];
    for (int i = 0; i < 64; ++i) {
        int64_t k = (int64_t)((i * 23) % 64);
        assert(llrb_put(&t, k, k * 10) == RED_BLACK_TREE_C11_OK);
        probes[i] = i;
    }
    assert(llrb_verify_properties(&t) == RED_BLACK_TREE_C11_OK);
    assert(llrb_parallel_count_present(&t, probes, 64) == 64);
    return 0;
}
