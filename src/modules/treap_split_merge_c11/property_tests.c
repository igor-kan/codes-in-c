#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(treap_split_merge_c11_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    treap_arena_t tr; treap_c_init(&tr);
    for (int i = 1; i <= 8; ++i) tr.root = treap_c_merge(&tr, tr.root, treap_c_new(&tr, i, (uint32_t)(i * 99991u)));
    assert(tr.pool[tr.root].sz == 8 && tr.pool[tr.root].sum == 36);
    return 0;
}
