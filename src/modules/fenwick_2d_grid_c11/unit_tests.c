#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(fenwick_2d_grid_c11_validate_len(1) == FENWICK_2D_GRID_C11_OK);
    fenwick2d_t fw; fw2d_init(&fw, 8, 8);
    fw2d_add(&fw, 1, 2, 5); fw2d_add(&fw, 3, 4, 7); fw2d_add(&fw, 0, 0, 9);
    assert(fw2d_rect_sum(&fw, 1, 1, 4, 4) == 12);
    assert(fw2d_rect_sum(&fw, 0, 0, 7, 7) == 21);
    assert(fenwick_2d_grid_c11_verify_guard(true) == FENWICK_2D_GRID_C11_OK);
    return 0;
}
