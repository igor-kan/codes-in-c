#include "interface.h"
#include <string.h>

static inline size_t min_sz(size_t a, size_t b) { return a < b ? a : b; }

kfifo_power2_ring_err_t kfifo_init(kfifo_t* q, uint8_t* backing, size_t power2_cap) {
    if (!q || !backing) return KFIFO_POWER2_RING_ERR_NULL;
    if (power2_cap < 2 || (power2_cap & (power2_cap - 1U)) != 0 || power2_cap > 0x80000000U) {
        return KFIFO_POWER2_RING_ERR_BOUNDS;
    }
    q->data = backing;
    q->mask = (uint32_t)(power2_cap - 1U);
    q->in = 0;
    q->out = 0;
    return KFIFO_POWER2_RING_OK;
}

size_t kfifo_len(const kfifo_t* q) { return (size_t)(q->in - q->out); }
size_t kfifo_avail(const kfifo_t* q) { return (size_t)(q->mask + 1U) - kfifo_len(q); }

size_t kfifo_in(kfifo_t* q, const uint8_t* src, size_t len) {
    if (!q || !src || len == 0) return 0;
    size_t l = min_sz(len, kfifo_avail(q));
    size_t cap = (size_t)q->mask + 1U;
    size_t off = (size_t)(q->in & q->mask);
    size_t first = min_sz(l, cap - off);
    memcpy(q->data + off, src, first);
    if (l > first) memcpy(q->data, src + first, l - first);
    q->in += (uint32_t)l;
    return l;
}

size_t kfifo_out(kfifo_t* q, uint8_t* dst, size_t len) {
    size_t l = kfifo_peek(q, dst, len);
    q->out += (uint32_t)l;
    return l;
}
