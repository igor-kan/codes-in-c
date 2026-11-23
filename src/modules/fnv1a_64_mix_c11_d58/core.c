#include "interface.h"
#include <math.h>
#include <string.h>

void fnv1a_init(fnv1a_stream_t *st) {
    st->state = 0xCBF29CE484222325ULL;
}

void fnv1a_update(fnv1a_stream_t *st, const uint8_t *buf, size_t n) {
    uint64_t h = st->state;
    for (size_t i = 0; i < n; ++i) {
        h ^= (uint64_t)buf[i];
        h *= 0x100000001B3ULL;
    }
    st->state = h;
}
