#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(segmented_sieve_c11_d61_validate_len(1) == SEGMENTED_SIEVE_C11_D61_OK);
    sieve_result_t sr;
    size_t n = segmented_sieve(10ULL, 40ULL, &sr);
    assert(n == 8 && sr.primes[0] == 11ULL && sr.primes[7] == 37ULL);
    uint64_t sum = 0;
    for (size_t i = 0; i < n; ++i) sum += sr.primes[i];
    assert(sum == 180ULL);
    assert(segmented_sieve_c11_d61_verify_guard(true) == SEGMENTED_SIEVE_C11_D61_OK);
    return 0;
}
