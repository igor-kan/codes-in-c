#include "interface.h"
#include <math.h>
#include <string.h>

size_t uleb128_encode(uint64_t val, uint8_t *dst) {
    size_t n = 0;
    do {
        uint8_t byte = (uint8_t)(val & 0x7Fu);
        val >>= 7;
        if (val != 0) byte |= 0x80u;
        dst[n++] = byte;
    } while (val != 0);
    return n;
}

int uleb128_decode(const uint8_t *src, size_t max_len, uint64_t *out, size_t *consumed) {
    uint64_t res = 0;
    uint32_t shift = 0;
    for (size_t i = 0; i < max_len && i < 10; ++i) {
        uint8_t b = src[i];
        res |= ((uint64_t)(b & 0x7Fu)) << shift;
        if ((b & 0x80u) == 0) {
            *out = res;
            *consumed = i + 1;
            return 0;
        }
        shift += 7;
    }
    return -1;
}

uint64_t zigzag_encode64(int64_t s) {
    return ((uint64_t)s << 1) ^ (uint64_t)(s >> 63);
}

int64_t zigzag_decode64(uint64_t u) {
    return (int64_t)((u >> 1) ^ (uint64_t)-(int64_t)(u & 1u));
}
