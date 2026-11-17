#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t orig[32], arr[32], stream[200], samp[12];
    for (size_t i = 0; i < 32; ++i) { orig[i] = (int64_t)i; arr[i] = (int64_t)i; }
    assert(fisher_yates_shuffle(arr, 32, 42ULL) == KNUTH_SHUFFLE_RESERVOIR_OK);
    assert(verify_permutation_parity(orig, arr, 32) == KNUTH_SHUFFLE_RESERVOIR_OK);
    for (size_t i = 0; i < 200; ++i) stream[i] = (int64_t)(i + 1);
    assert(reservoir_sample_l(stream, 200, samp, 12, 99ULL) == KNUTH_SHUFFLE_RESERVOIR_OK);
    for (size_t i = 0; i < 12; ++i) assert(samp[i] >= 1 && samp[i] <= 200);
    return 0;
}
