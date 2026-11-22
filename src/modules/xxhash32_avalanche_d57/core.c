#include "interface.h"
#include <math.h>
#include <string.h>

static uint32_t rotl32_xx(uint32_t x, int r) { return (x << r) | (x >> (32 - r)); }
static uint32_t rd32_xx(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

uint32_t xxhash32_compute(const uint8_t *buf, size_t len, uint32_t seed) {
    const uint32_t P1 = 0x9E3779B1u, P2 = 0x85EBCA77u, P3 = 0xC2B2AE3Du, P4 = 0x27D4EB2Fu, P5 = 0x165667B1u;
    uint32_t h;
    size_t i = 0;
    if (len >= 16) {
        uint32_t v1 = seed + P1 + P2, v2 = seed + P2, v3 = seed, v4 = seed - P1;
        while (i + 16 <= len) {
            v1 = rotl32_xx(v1 + rd32_xx(buf + i) * P2, 13) * P1;
            v2 = rotl32_xx(v2 + rd32_xx(buf + i + 4) * P2, 13) * P1;
            v3 = rotl32_xx(v3 + rd32_xx(buf + i + 8) * P2, 13) * P1;
            v4 = rotl32_xx(v4 + rd32_xx(buf + i + 12) * P2, 13) * P1;
            i += 16;
        }
        h = rotl32_xx(v1, 1) + rotl32_xx(v2, 7) + rotl32_xx(v3, 12) + rotl32_xx(v4, 18);
    } else {
        h = seed + P5;
    }
    h += (uint32_t)len;
    while (i + 4 <= len) {
        h = rotl32_xx(h + rd32_xx(buf + i) * P3, 17) * P4;
        i += 4;
    }
    while (i < len) {
        h = rotl32_xx(h + (uint32_t)buf[i] * P5, 11) * P1;
        ++i;
    }
    h ^= h >> 15; h *= P2;
    h ^= h >> 13; h *= P3;
    return h ^ (h >> 16);
}
