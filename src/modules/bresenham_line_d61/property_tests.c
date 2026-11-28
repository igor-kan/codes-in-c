#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(bresenham_line_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    bres_line_t ln;
    size_t n = bresenham_line(-4, -2, 9, 7, &ln);
    assert(n == 14);
    assert(ln.pts[0].x == -4 && ln.pts[0].y == -2);
    assert(ln.pts[n - 1].x == 9 && ln.pts[n - 1].y == 7);
    for (size_t i = 1; i < n; ++i) {
        int32_t ddx = ln.pts[i].x - ln.pts[i - 1].x;
        int32_t ddy = ln.pts[i].y - ln.pts[i - 1].y;
        if (ddx < 0) ddx = -ddx;
        if (ddy < 0) ddy = -ddy;
        assert(ddx <= 1 && ddy <= 1 && ddx + ddy >= 1);
    }
    return 0;
}
