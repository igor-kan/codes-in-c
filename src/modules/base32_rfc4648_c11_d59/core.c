#include "interface.h"
#include <math.h>
#include <string.h>

static const uint8_t B32_ALPHA[32] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z','2','3','4','5','6','7'
};

static int b32_idx(uint8_t c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= '2' && c <= '7') return c - '2' + 26;
    return -1;
}

size_t b32_encode(const uint8_t *src, size_t len, uint8_t *dst) {
    size_t i = 0, o = 0;
    while (i < len) {
        size_t rem = len - i;
        uint64_t blk = 0;
        for (size_t k = 0; k < 5 && i + k < len; ++k) blk |= ((uint64_t)src[i + k]) << (32 - 8 * k);
        size_t chars = (rem * 8 + 4) / 5;
        for (size_t c = 0; c < 8; ++c) {
            dst[o++] = (c < chars) ? B32_ALPHA[(blk >> (35 - 5 * c)) & 31u] : (uint8_t)'=';
        }
        i += 5;
    }
    return o;
}

int b32_decode(const uint8_t *src, size_t len, uint8_t *dst, size_t *out_len) {
    if ((len & 7u) != 0) return -1;
    size_t o = 0;
    for (size_t i = 0; i < len; i += 8) {
        uint64_t blk = 0;
        size_t pad = 0;
        for (size_t c = 0; c < 8; ++c) {
            if (src[i + c] == '=') { ++pad; }
            else {
                if (pad > 0) return -1;
                int v = b32_idx(src[i + c]);
                if (v < 0) return -1;
                blk |= ((uint64_t)v) << (35 - 5 * c);
            }
        }
        size_t bytes = (pad == 0) ? 5 : (pad == 1 ? 4 : (pad == 3 ? 3 : (pad == 4 ? 2 : (pad == 6 ? 1 : 99))));
        if (bytes == 99) return -1;
        for (size_t k = 0; k < bytes; ++k) dst[o++] = (uint8_t)((blk >> (32 - 8 * k)) & 0xFFu);
    }
    *out_len = o;
    return 0;
}
