#include "interface.h"
#include <string.h>

static const uint64_t P1 = 0x9E3779B185EBCA87ULL;
static const uint64_t P2 = 0xC2B2AE3D27D4EB4FULL;
static const uint64_t P3 = 0x165667B19E3779F9ULL;
static const uint64_t P4 = 0x85EBCA77C2B2AE63ULL;
static const uint64_t P5 = 0x27D4EB2F165667C5ULL;

static inline uint64_t rotl64(uint64_t x, int r) { return (x << r) | (x >> (64 - r)); }
static inline uint64_t read64le(const uint8_t* p) {
    uint64_t v = 0;
    memcpy(&v, p, sizeof(v));
    return v;
}
static inline uint32_t read32le(const uint8_t* p) {
    uint32_t v = 0;
    memcpy(&v, p, sizeof(v));
    return v;
}
static inline uint64_t xxh_round(uint64_t acc, uint64_t input) {
    acc += input * P2;
    acc = rotl64(acc, 31);
    return acc * P1;
}
static inline uint64_t merge_round(uint64_t acc, uint64_t val) {
    val = xxh_round(0, val);
    acc ^= val;
    return acc * P1 + P4;
}
static inline uint64_t avalanche(uint64_t h) {
    h ^= h >> 33;
    h *= P2;
    h ^= h >> 29;
    h *= P3;
    h ^= h >> 32;
    return h;
}

void xxhash64_streaming_reset(xxhash64_state_t* st, uint64_t seed) {
    if (!st) return;
    memset(st, 0, sizeof(*st));
    st->seed = seed;
    st->v1 = seed + P1 + P2;
    st->v2 = seed + P2;
    st->v3 = seed;
    st->v4 = seed - P1;
}

xxhash64_streaming_err_t xxhash64_streaming_update(xxhash64_state_t* st, const void* data, size_t len) {
    if (!st || (len > 0 && !data)) return XXHASH64_STREAMING_ERR_NULL;
    if (len == 0) return XXHASH64_STREAMING_OK;
    const uint8_t* p = (const uint8_t*)data;
    const uint8_t* b_end = p + len;
    st->total_len += len;

    if (st->memsize + len < 32U) {
        memcpy(st->mem64 + st->memsize, p, len);
        st->memsize += len;
        return XXHASH64_STREAMING_OK;
    }
    if (st->memsize > 0) {
        size_t fill = 32U - st->memsize;
        memcpy(st->mem64 + st->memsize, p, fill);
        st->v1 = xxh_round(st->v1, read64le(st->mem64));
        st->v2 = xxh_round(st->v2, read64le(st->mem64 + 8));
        st->v3 = xxh_round(st->v3, read64le(st->mem64 + 16));
        st->v4 = xxh_round(st->v4, read64le(st->mem64 + 24));
        p += fill;
        st->memsize = 0;
    }
    while (p + 32 <= b_end) {
        st->v1 = xxh_round(st->v1, read64le(p));
        st->v2 = xxh_round(st->v2, read64le(p + 8));
        st->v3 = xxh_round(st->v3, read64le(p + 16));
        st->v4 = xxh_round(st->v4, read64le(p + 24));
        p += 32;
    }
    if (p < b_end) {
        st->memsize = (size_t)(b_end - p);
        memcpy(st->mem64, p, st->memsize);
    }
    return XXHASH64_STREAMING_OK;
}

uint64_t xxhash64_streaming_digest(const xxhash64_state_t* st) {
    if (!st) return 0;
    uint64_t h64;
    if (st->total_len >= 32U) {
        h64 = rotl64(st->v1, 1) + rotl64(st->v2, 7) + rotl64(st->v3, 12) + rotl64(st->v4, 18);
        h64 = merge_round(h64, st->v1);
        h64 = merge_round(h64, st->v2);
        h64 = merge_round(h64, st->v3);
        h64 = merge_round(h64, st->v4);
    } else {
        h64 = st->seed + P5;
    }
    h64 += st->total_len;
    const uint8_t* p = st->mem64;
    const uint8_t* end = p + st->memsize;
    while (p + 8 <= end) {
        uint64_t k1 = xxh_round(0, read64le(p));
        h64 ^= k1;
        h64 = rotl64(h64, 27) * P1 + P4;
        p += 8;
    }
    if (p + 4 <= end) {
        h64 ^= (uint64_t)read32le(p) * P1;
        h64 = rotl64(h64, 23) * P2 + P3;
        p += 4;
    }
    while (p < end) {
        h64 ^= (uint64_t)(*p) * P5;
        h64 = rotl64(h64, 11) * P1;
        p++;
    }
    return avalanche(h64);
}

uint64_t xxhash64_streaming_oneshot(const void* data, size_t len, uint64_t seed) {
    xxhash64_state_t st;
    xxhash64_streaming_reset(&st, seed);
    xxhash64_streaming_update(&st, data, len);
    return xxhash64_streaming_digest(&st);
}
