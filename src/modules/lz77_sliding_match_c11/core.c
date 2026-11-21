#include "interface.h"
#include <math.h>
#include <string.h>

size_t lz77_compress(const uint8_t *src, size_t len, size_t window, lz77_token_t *out, size_t max_tok) {
    size_t pos = 0;
    size_t cnt = 0;
    while (pos < len && cnt < max_tok) {
        size_t best_off = 0;
        size_t best_len = 0;
        size_t start = pos > window ? pos - window : 0;
        for (size_t j = start; j < pos; ++j) {
            size_t l = 0;
            while (pos + l + 1 < len && src[j + l] == src[pos + l] && l < 32) ++l;
            if (l > best_len) {
                best_len = l;
                best_off = pos - j;
            }
        }
        uint8_t lit = src[pos + best_len];
        out[cnt++] = (lz77_token_t){(uint16_t)best_off, (uint16_t)best_len, lit};
        pos += best_len + 1;
    }
    return cnt;
}

size_t lz77_decompress(const lz77_token_t *tok, size_t ntok, uint8_t *dst) {
    size_t pos = 0;
    for (size_t i = 0; i < ntok; ++i) {
        for (uint16_t k = 0; k < tok[i].length; ++k) {
            dst[pos] = dst[pos - tok[i].offset];
            ++pos;
        }
        dst[pos++] = tok[i].next_char;
    }
    return pos;
}
