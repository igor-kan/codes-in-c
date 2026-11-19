#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(zkw_bottom_up_segtree_c_validate_len(1) == ZKW_BOTTOM_UP_SEGTREE_C_OK);
    zkw_tree_t z; zkw_init(&z);
    for (int i = 0; i < 6; ++i) zkw_set(&z, i, (i + 1) * 10);
    assert(zkw_sum(&z, 1, 4) == 140);
    zkw_set(&z, 2, 100);
    assert(zkw_sum(&z, 1, 4) == 210);
    assert(zkw_bottom_up_segtree_c_verify_guard(true) == ZKW_BOTTOM_UP_SEGTREE_C_OK);
    return 0;
}
