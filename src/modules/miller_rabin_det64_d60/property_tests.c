#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(miller_rabin_det64_d60_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    assert(is_prime_u64_d60(1000000007ULL));
    assert(!is_prime_u64_d60(1000000007ULL * 1000000009ULL % 4294967295ULL + 4ULL));
    return 0;
}
