#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(delta_zig_frame_c11_d57_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const int64_t vals[4] = {-50, -40, -25, -5};
    int64_t e[4], d[4];
    delta_encode(vals, 4, e);
    delta_decode(e, 4, d);
    for (int i = 0; i < 4; ++i) assert(d[i] == vals[i]);
    return 0;
}
