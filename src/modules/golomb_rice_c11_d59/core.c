#include "interface.h"
#include <math.h>
#include <string.h>

size_t gr_encode_bits(const uint32_t *vals, size_t n, uint32_t k, uint8_t *bits_out) {
    size_t pos = 0;
    for (size_t i = 0; i < n; ++i) {
        uint32_t q = vals[i] >> k;
        uint32_t r = vals[i] & ((1u << k) - 1u);
        for (uint32_t z = 0; z < q; ++z) bits_out[pos++] = 1;
        bits_out[pos++] = 0;
        for (int b = (int)k - 1; b >= 0; --b) bits_out[pos++] = (uint8_t)((r >> b) & 1u);
    }
    return pos;
}

size_t gr_decode_bits(const uint8_t *bits, size_t n_bits, uint32_t k, uint32_t *out) {
    size_t i = 0, cnt = 0;
    while (i < n_bits) {
        uint32_t q = 0;
        while (i < n_bits && bits[i] == 1) { ++q; ++i; }
        if (i >= n_bits) break;
        ++i;
        uint32_t r = 0;
        for (uint32_t b = 0; b < k && i < n_bits; ++b) { r = (r << 1) | bits[i++]; }
        out[cnt++] = (q << k) | r;
    }
    return cnt;
}
