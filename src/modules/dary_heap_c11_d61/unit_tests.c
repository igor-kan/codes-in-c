#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(dary_heap_c11_d61_validate_len(1) == DARY_HEAP_C11_D61_OK);
    dary_heap_t h; dary_heap_init(&h);
    int64_t vals[6] = {5, 3, 8, 1, 9, 2};
    for (int i = 0; i < 6; ++i) assert(dary_heap_push(&h, vals[i]));
    int64_t top = 0;
    assert(dary_heap_peek(&h, &top) && top == 1);
    int64_t expect[6] = {1, 2, 3, 5, 8, 9};
    for (int i = 0; i < 6; ++i) {
        int64_t out = 0;
        assert(dary_heap_pop(&h, &out) && out == expect[i]);
    }
    assert(!dary_heap_pop(&h, &top));
    assert(dary_heap_c11_d61_verify_guard(true) == DARY_HEAP_C11_D61_OK);
    return 0;
}
