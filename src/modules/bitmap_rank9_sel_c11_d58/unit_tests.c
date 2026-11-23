#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(bitmap_rank9_sel_c11_d58_validate_len(1) == BITMAP_RANK9_SEL_C11_D58_OK);
    uint64_t w = (1ULL << 2) | (1ULL << 7) | (1ULL << 40);
    assert(word_popcount64(w) == 3);
    assert(word_rank64(w, 7) == 2);
    assert(word_select64(w, 1) == 7 && word_select64(w, 2) == 40);
    assert(bitmap_rank9_sel_c11_d58_verify_guard(true) == BITMAP_RANK9_SEL_C11_D58_OK);
    return 0;
}
