#include "interface.h"
#include <math.h>
#include <string.h>

size_t pvar_encode(uint64_t v, uint8_t *dst) {
    if (v < 240ULL) { dst[0] = (uint8_t)v; return 1; }
    if (v < 2288ULL) {
        uint64_t adj = v - 240ULL;
        dst[0] = (uint8_t)(240ULL + (adj >> 8));
        dst[1] = (uint8_t)(adj & 0xFFu);
        return 2;
    }
    uint8_t k = 0;
    uint64_t tmp = v;
    while (tmp > 0) { tmp >>= 8; ++k; }
    dst[0] = (uint8_t)(247u + k);
    for (uint8_t i = 0; i < k; ++i) dst[1 + i] = (uint8_t)((v >> (8 * i)) & 0xFFu);
    return (size_t)(1u + k);
}

int pvar_decode(const uint8_t *src, size_t avail, uint64_t *out, size_t *used) {
    if (avail == 0) return -1;
    uint8_t tag = src[0];
    if (tag < 240u) { *out = tag; *used = 1; return 0; }
    if (tag <= 247u) {
        if (avail < 2) return -1;
        *out = 240ULL + (((uint64_t)(tag - 240u)) << 8) + src[1];
        *used = 2;
        return 0;
    }
    size_t k = (size_t)(tag - 247u);
    if (k > 8 || avail < 1 + k) return -1;
    uint64_t res = 0;
    for (size_t i = 0; i < k; ++i) res |= ((uint64_t)src[1 + i]) << (8 * i);
    *out = res; *used = 1 + k;
    return 0;
}
