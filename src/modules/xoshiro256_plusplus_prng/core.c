#include "interface.h"

static inline uint64_t rotl64_xo(uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
}

static uint64_t sm64(uint64_t* s) {
    uint64_t z = (*s += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

xoshiro256_plusplus_prng_err_t xoshiro_seed(xoshiro256pp_state_t* st, uint64_t seed) {
    if (!st) return XOSHIRO256_PLUSPLUS_PRNG_ERR_NULL;
    uint64_t tmp = seed ? seed : 0x1ULL;
    for (int i = 0; i < 4; ++i) st->s[i] = sm64(&tmp);
    return XOSHIRO256_PLUSPLUS_PRNG_OK;
}

uint64_t xoshiro_next(xoshiro256pp_state_t* st) {
    const uint64_t result = rotl64_xo(st->s[0] + st->s[3], 23) + st->s[0];
    const uint64_t t = st->s[1] << 17;
    st->s[2] ^= st->s[0];
    st->s[3] ^= st->s[1];
    st->s[1] ^= st->s[2];
    st->s[0] ^= st->s[3];
    st->s[2] ^= t;
    st->s[3] = rotl64_xo(st->s[3], 45);
    return result;
}

void xoshiro_jump(xoshiro256pp_state_t* st) {
    static const uint64_t JUMP[4] = {
        0x180ec6d33cfd0abaULL, 0xd5a61266f0c9392cULL,
        0xa9582618e03fc9aaULL, 0x39abdc4529b1661cULL
    };
    uint64_t s0 = 0, s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < 4; ++i) {
        for (int b = 0; b < 64; ++b) {
            if (JUMP[i] & (UINT64_C(1) << b)) {
                s0 ^= st->s[0];
                s1 ^= st->s[1];
                s2 ^= st->s[2];
                s3 ^= st->s[3];
            }
            xoshiro_next(st);
        }
    }
    st->s[0] = s0; st->s[1] = s1; st->s[2] = s2; st->s[3] = s3;
}
