#include "interface.h"

knuth_shuffle_reservoir_err_t verify_permutation_parity(const int64_t* orig, const int64_t* shuf, size_t n) {
    if (!orig || !shuf) return KNUTH_SHUFFLE_RESERVOIR_ERR_NULL;
    int64_t sum_a = 0, sum_b = 0, xor_a = 0, xor_b = 0;
    for (size_t i = 0; i < n; ++i) {
        sum_a += orig[i]; sum_b += shuf[i];
        xor_a ^= orig[i]; xor_b ^= shuf[i];
    }
    return (sum_a == sum_b && xor_a == xor_b) ? KNUTH_SHUFFLE_RESERVOIR_OK : KNUTH_SHUFFLE_RESERVOIR_ERR_INVARIANT;
}
