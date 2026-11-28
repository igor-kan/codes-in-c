#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(segmented_sieve_c11_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    sieve_result_t all;
    assert(segmented_sieve(2ULL, 100ULL, &all) == 25);
    assert(all.primes[24] == 97ULL);
    for (size_t i = 0; i < all.count; ++i) {
        uint64_t p = all.primes[i];
        for (uint64_t d = 2ULL; d * d <= p; ++d) assert(p % d != 0ULL);
    }
    return 0;
}
