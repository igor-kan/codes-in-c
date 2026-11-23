#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(fnv1a_64_mix_c11_d58_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    fnv1a_stream_t a, b; fnv1a_init(&a); fnv1a_init(&b);
    const uint8_t x[2] = {1, 2}, y[2] = {1, 3};
    fnv1a_update(&a, x, 2); fnv1a_update(&b, y, 2);
    assert(a.state != b.state);
    return 0;
}
