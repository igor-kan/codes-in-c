#include "interface.h"
#include <math.h>
#include <string.h>

size_t lz77_encode_d60(const uint8_t* in, size_t n, lz77_tok_t* out, size_t cap) {
    size_t i = 0, cnt = 0;
    while (i < n && cnt < cap) {
        uint16_t best_dist = 0, best_len = 0;
        size_t start = (i > 64U) ? (i - 64U) : 0U;
        for (size_t j = start; j < i; ++j) {
            uint16_t l = 0;
            while (i + l + 1U < n && in[j + l] == in[i + l] && l < 32U) ++l;
            if (l > best_len) {
                best_len = l;
                best_dist = (uint16_t)(i - j);
            }
        }
        uint8_t nxt = in[i + best_len];
        out[cnt++] = (lz77_tok_t){best_dist, best_len, nxt};
        i += (size_t)best_len + 1U;
    }
    return cnt;
}
size_t lz77_decode_d60(const lz77_tok_t* toks, size_t ntoks, uint8_t* out, size_t cap) {
    size_t pos = 0;
    for (size_t t = 0; t < ntoks; ++t) {
        size_t src = pos - toks[t].dist;
        for (uint16_t k = 0; k < toks[t].len && pos < cap; ++k) {
            out[pos] = out[src + k];
            ++pos;
        }
        if (pos < cap) out[pos++] = toks[t].next_ch;
    }
    return pos;
}
