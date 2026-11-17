#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t a[64], b[64], orig[64];
    for (size_t i = 0; i < 64; ++i) a[i] = b[i] = orig[i] = (int64_t)i;
    parallel_independent_shuffles(a, b, 64, 12345ULL);
    assert(verify_permutation_parity(orig, a, 64) == KNUTH_SHUFFLE_RESERVOIR_OK);
    assert(verify_permutation_parity(orig, b, 64) == KNUTH_SHUFFLE_RESERVOIR_OK);
    return 0;
}
