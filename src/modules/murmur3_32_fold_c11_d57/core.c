#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32_m3(uint32_t x, int r) { return (x << r) | (x >> (32 - r)); }

uint32_t murmur3_32(const uint8_t *key, size_t len, uint32_t seed) {
    uint32_t h1 = seed;
    const uint32_t c1 = 0xCC9E2D51u, c2 = 0x1B873593u;
    size_t nblocks = len / 4;
    for (size_t i = 0; i < nblocks; ++i) {
        const uint8_t *p = key + i * 4;
        uint32_t k1 = (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
        k1 *= c1; k1 = rotl32_m3(k1, 15); k1 *= c2;
        h1 ^= k1; h1 = rotl32_m3(h1, 13);
        h1 = h1 * 5u + 0xE6546B64u;
    }
    const uint8_t *tail = key + nblocks * 4;
    uint32_t k1 = 0;
    size_t rem = len & 3u;
    if (rem >= 3) k1 ^= (uint32_t)tail[2] << 16;
    if (rem >= 2) k1 ^= (uint32_t)tail[1] << 8;
    if (rem >= 1) { k1 ^= (uint32_t)tail[0]; k1 *= c1; k1 = rotl32_m3(k1, 15); k1 *= c2; h1 ^= k1; }
    h1 ^= (uint32_t)len;
    h1 ^= h1 >> 16; h1 *= 0x85EBCA6Bu;
    h1 ^= h1 >> 13; h1 *= 0xC2B2AE35u;
    return h1 ^ (h1 >> 16);
}
