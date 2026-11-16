#include "interface.h"
#include <string.h>

size_t kfifo_peek(const kfifo_t* q, uint8_t* dst, size_t len) {
    if (!q || !dst || len == 0) return 0;
    size_t avail = kfifo_len(q);
    size_t l = len < avail ? len : avail;
    size_t cap = (size_t)q->mask + 1U;
    size_t off = (size_t)(q->out & q->mask);
    size_t first = l < (cap - off) ? l : (cap - off);
    memcpy(dst, q->data + off, first);
    if (l > first) memcpy(dst + first, q->data, l - first);
    return l;
}
