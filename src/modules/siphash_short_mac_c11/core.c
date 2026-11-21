#include "interface.h"
#include <math.h>
#include <string.h>

static uint64_t rotl64_sip(uint64_t x, int b) {
    return (x << b) | (x >> (64 - b));
}

static void sipround(uint64_t *v0, uint64_t *v1, uint64_t *v2, uint64_t *v3) {
    *v0 += *v1; *v1 = rotl64_sip(*v1, 13); *v1 ^= *v0; *v0 = rotl64_sip(*v0, 32);
    *v2 += *v3; *v3 = rotl64_sip(*v3, 16); *v3 ^= *v2;
    *v0 += *v3; *v3 = rotl64_sip(*v3, 21); *v3 ^= *v0;
    *v2 += *v1; *v1 = rotl64_sip(*v1, 17); *v1 ^= *v2; *v2 = rotl64_sip(*v2, 32);
}

static uint64_t load_le64(const uint8_t *p) {
    return (uint64_t)p[0] | ((uint64_t)p[1] << 8) | ((uint64_t)p[2] << 16) | ((uint64_t)p[3] << 24) |
           ((uint64_t)p[4] << 32) | ((uint64_t)p[5] << 40) | ((uint64_t)p[6] << 48) | ((uint64_t)p[7] << 56);
}

uint64_t siphash24(uint64_t k0, uint64_t k1, const uint8_t *msg, size_t len) {
    uint64_t v0 = 0x736f6d6570736575ULL ^ k0;
    uint64_t v1 = 0x646f72616e646f6dULL ^ k1;
    uint64_t v2 = 0x6c7967656e657261ULL ^ k0;
    uint64_t v3 = 0x7465646279746573ULL ^ k1;
    size_t blocks = len / 8;
    for (size_t i = 0; i < blocks; ++i) {
        uint64_t m = load_le64(msg + i * 8);
        v3 ^= m;
        sipround(&v0, &v1, &v2, &v3);
        sipround(&v0, &v1, &v2, &v3);
        v0 ^= m;
    }
    uint64_t b = ((uint64_t)len & 0xFFULL) << 56;
    const uint8_t *tail = msg + blocks * 8;
    size_t rem = len & 7u;
    for (size_t i = 0; i < rem; ++i) b |= ((uint64_t)tail[i]) << (8u * i);
    v3 ^= b;
    sipround(&v0, &v1, &v2, &v3);
    sipround(&v0, &v1, &v2, &v3);
    v0 ^= b;
    v2 ^= 0xFFULL;
    for (int i = 0; i < 4; ++i) sipround(&v0, &v1, &v2, &v3);
    return v0 ^ v1 ^ v2 ^ v3;
}
