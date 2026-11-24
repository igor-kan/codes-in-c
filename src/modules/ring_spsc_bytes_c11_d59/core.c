#include "interface.h"
#include <math.h>
#include <string.h>

void br64_init(byte_ring64_t *r) {
    r->head = 0; r->tail = 0; r->used = 0;
}

int br64_write(byte_ring64_t *r, const uint8_t *src, size_t n) {
    if (n > 64u - r->used) return -1;
    for (size_t i = 0; i < n; ++i) {
        r->buf[r->tail] = src[i];
        r->tail = (r->tail + 1u) & 63u;
    }
    r->used += n;
    return 0;
}

size_t br64_read(byte_ring64_t *r, uint8_t *dst, size_t n) {
    size_t take = n < r->used ? n : r->used;
    for (size_t i = 0; i < take; ++i) {
        dst[i] = r->buf[r->head];
        r->head = (r->head + 1u) & 63u;
    }
    r->used -= take;
    return take;
}
