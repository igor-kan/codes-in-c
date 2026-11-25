#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t mulmod_u64_d60(uint64_t a, uint64_t b, uint64_t mod) {
    return (uint64_t)(((__uint128_t)a * b) % mod);
}
uint64_t powmod_u64_d60(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1ULL;
    base %= mod;
    while (exp > 0) {
        if (exp & 1ULL) res = mulmod_u64_d60(res, base, mod);
        base = mulmod_u64_d60(base, base, mod);
        exp >>= 1;
    }
    return res;
}
bool is_prime_u64_d60(uint64_t n) {
    if (n < 2ULL) return false;
    static const uint64_t bases[7] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (uint64_t p = 2; p <= 7; ++p) {
        if (n % p == 0) return n == p;
    }
    uint64_t d = n - 1ULL;
    int s = 0;
    while ((d & 1ULL) == 0ULL) { d >>= 1; ++s; }
    for (size_t i = 0; i < 7; ++i) {
        uint64_t a = bases[i] % n;
        if (a == 0ULL) continue;
        uint64_t x = powmod_u64_d60(a, d, n);
        if (x == 1ULL || x == n - 1ULL) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = mulmod_u64_d60(x, x, n);
            if (x == n - 1ULL) { composite = false; break; }
        }
        if (composite) return false;
    }
    return true;
}
