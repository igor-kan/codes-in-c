#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(bitmap_rank9_sel_c11_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    uint64_t w = 0xAA00ULL;
    int p0 = word_select64(w, 0);
    assert(word_rank64(w, p0) == 1);
    return 0;
}
