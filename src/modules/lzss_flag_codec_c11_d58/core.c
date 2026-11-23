#include "interface.h"
#include <math.h>
#include <string.h>

size_t lzss_compress(const uint8_t *src, size_t n, lzss_op_t *ops) {
    size_t i = 0, out = 0;
    while (i < n) {
        size_t best_off = 0, best_len = 0;
        size_t start = i > 32 ? i - 32 : 0;
        for (size_t j = start; j < i; ++j) {
            size_t l = 0;
            while (i + l < n && src[j + l] == src[i + l] && l < 32) ++l;
            if (l > best_len) { best_len = l; best_off = i - j; }
        }
        if (best_len >= 3) {
            ops[out++] = (lzss_op_t){1, (uint8_t)best_off, (uint8_t)best_len};
            i += best_len;
        } else {
            ops[out++] = (lzss_op_t){0, src[i++], 0};
        }
    }
    return out;
}

size_t lzss_decompress(const lzss_op_t *ops, size_t n_ops, uint8_t *dst) {
    size_t pos = 0;
    for (size_t i = 0; i < n_ops; ++i) {
        if (ops[i].is_match == 0) {
            dst[pos++] = ops[i].val_or_off;
        } else {
            for (uint8_t k = 0; k < ops[i].len; ++k) {
                dst[pos] = dst[pos - ops[i].val_or_off];
                ++pos;
            }
        }
    }
    return pos;
}
