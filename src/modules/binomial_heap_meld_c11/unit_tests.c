#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(binomial_heap_meld_c11_validate_len(1) == BINOMIAL_HEAP_MELD_C11_OK);
    binom_heap_t h; bh_init(&h);
    int64_t vals[6] = {42, 7, 19, 3, 25, 11};
    for (int i = 0; i < 6; ++i) bh_push(&h, vals[i]);
    assert(bh_pop_min(&h) == 3 && bh_pop_min(&h) == 7 && bh_pop_min(&h) == 11);
    assert(binomial_heap_meld_c11_verify_guard(true) == BINOMIAL_HEAP_MELD_C11_OK);
    return 0;
}
