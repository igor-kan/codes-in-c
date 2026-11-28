#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(bresenham_line_d61_validate_len(1) == BRESENHAM_LINE_D61_OK);
    bres_line_t ln;
    size_t n = bresenham_line(0, 0, 3, 2, &ln);
    assert(n == 4 && ln.pts[0].x == 0 && ln.pts[0].y == 0);
    assert(ln.pts[n - 1].x == 3 && ln.pts[n - 1].y == 2);
    size_t m = bresenham_line(2, 0, 2, 3, &ln);
    assert(m == 4);
    for (size_t i = 0; i < m; ++i) assert(ln.pts[i].x == 2);
    assert(bresenham_line_d61_verify_guard(true) == BRESENHAM_LINE_D61_OK);
    return 0;
}
