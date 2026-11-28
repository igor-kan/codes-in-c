#include "interface.h"
#include <math.h>
#include <string.h>

size_t segmented_sieve(uint64_t low, uint64_t high, sieve_result_t* out) {
    if (out == NULL) return 0;
    out->count = 0;
    if (high < 2ULL || low > high) return 0;
    uint64_t limit = 1ULL;
    while ((limit + 1ULL) * (limit + 1ULL) <= high) ++limit;
    uint8_t base[1024];
    if (limit > 1023ULL) limit = 1023ULL;
    memset(base, 1, sizeof(base));
    base[0] = 0;
    base[1] = 0;
    for (uint64_t i = 2ULL; i * i <= limit; ++i) {
        if (!base[i]) continue;
        for (uint64_t j = i * i; j <= limit; j += i) base[j] = 0;
    }
    uint64_t start = (low < 2ULL) ? 2ULL : low;
    uint8_t seg[512];
    while (start <= high && out->count < (size_t)SIEVE_MAX_PRIMES) {
        uint64_t end = start + 511ULL;
        if (end > high) end = high;
        size_t blen = (size_t)(end - start + 1ULL);
        memset(seg, 1, blen);
        for (uint64_t p = 2ULL; p <= limit; ++p) {
            if (!base[p]) continue;
            uint64_t first = (start + p - 1ULL) / p * p;
            if (first < p * p) first = p * p;
            for (uint64_t m = first; m <= end; m += p) {
                seg[(size_t)(m - start)] = 0;
            }
        }
        for (size_t i = 0; i < blen && out->count < (size_t)SIEVE_MAX_PRIMES; ++i) {
            if (seg[i]) out->primes[out->count++] = start + i;
        }
        start = end + 1ULL;
    }
    return out->count;
}
