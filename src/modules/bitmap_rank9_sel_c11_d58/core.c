#include "interface.h"
#include <math.h>
#include <string.h>

int word_popcount64(uint64_t x) {
    x = x - ((x >> 1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
    return (int)((x * 0x0101010101010101ULL) >> 56);
}

int word_rank64(uint64_t w, int pos) {
    if (pos < 0) return 0;
    if (pos >= 63) return word_popcount64(w);
    uint64_t mask = (1ULL << (pos + 1)) - 1ULL;
    return word_popcount64(w & mask);
}

int word_select64(uint64_t w, int k) {
    int seen = 0;
    for (int i = 0; i < 64; ++i) {
        if ((w >> i) & 1ULL) {
            if (seen == k) return i;
            ++seen;
        }
    }
    return -1;
}
