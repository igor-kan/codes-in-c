#include "interface.h"
#include <math.h>
#include <string.h>

void spsc_init_d60(spsc_ring_t* q) {
    memset(q->buf, 0, sizeof(q->buf));
    q->head = 0;
    q->tail = 0;
}
size_t spsc_size_d60(const spsc_ring_t* q) {
    return q->tail - q->head;
}
bool spsc_push_d60(spsc_ring_t* q, int64_t val) {
    if (spsc_size_d60(q) >= SPSC_CAP) return false;
    q->buf[q->tail & (SPSC_CAP - 1U)] = val;
    q->tail += 1U;
    return true;
}
bool spsc_pop_d60(spsc_ring_t* q, int64_t* out) {
    if (q->head == q->tail) return false;
    *out = q->buf[q->head & (SPSC_CAP - 1U)];
    q->head += 1U;
    return true;
}
