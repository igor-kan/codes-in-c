#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(shell_sort_ciura_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    int64_t a[64];
    int64_t sum_before = 0, sum_after = 0;
    uint64_t xor_before = 0, xor_after = 0;
    for (size_t i = 0; i < 64; ++i) {
        a[i] = (int64_t)((i * 37 + 5) % 211) - 100;
        sum_before += a[i];
        xor_before ^= (uint64_t)a[i];
    }
    shell_sort_ciura(a, 64);
    for (size_t i = 0; i < 64; ++i) {
        sum_after += a[i];
        xor_after ^= (uint64_t)a[i];
        if (i > 0) assert(a[i - 1] <= a[i]);
    }
    assert(sum_before == sum_after && xor_before == xor_after);
    return 0;
}
