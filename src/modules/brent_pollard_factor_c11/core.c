#include "interface.h"
#include <math.h>
#include <string.h>

uint64_t brent_gcd_u64(uint64_t a, uint64_t b) {
    while (b != 0) { uint64_t t = a % b; a = b; b = t; }
    return a;
}
static uint64_t mul_mod_u64(uint64_t a, uint64_t b, uint64_t m) {
    return (uint64_t)(((__uint128_t)a * b) % m);
}
uint64_t brent_pollard_rho(uint64_t n, uint64_t c) {
    if ((n & 1ULL) == 0) return 2;
    uint64_t y = 2, r = 1, q = 1, g = 1, x = 2, ys = 2;
    while (g == 1) {
        x = y;
        for (uint64_t i = 0; i < r; ++i) y = (mul_mod_u64(y, y, n) + c) % n;
        uint64_t k = 0;
        while (k < r && g == 1) {
            ys = y;
            uint64_t lim = (r - k < 16ULL) ? (r - k) : 16ULL;
            for (uint64_t i = 0; i < lim; ++i) {
                y = (mul_mod_u64(y, y, n) + c) % n;
                uint64_t diff = x > y ? x - y : y - x;
                q = mul_mod_u64(q, diff, n);
            }
            g = brent_gcd_u64(q, n);
            k += lim;
        }
        r <<= 1;
    }
    if (g == n) {
        do {
            ys = (mul_mod_u64(ys, ys, n) + c) % n;
            uint64_t diff = x > ys ? x - ys : ys - x;
            g = brent_gcd_u64(diff, n);
        } while (g == 1);
    }
    return g;
}
