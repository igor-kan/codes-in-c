#include "interface.h"
#include <math.h>
#include <string.h>

void spsc16_init(spsc_ring16_t *q) {
    q->head = 0;
    q->tail = 0;
}

uint32_t spsc16_len(const spsc_ring16_t *q) {
    return q->tail - q->head;
}

int spsc16_push(spsc_ring16_t *q, uint64_t v) {
    if ((uint32_t)(q->tail - q->head) >= 16u) return -1;
    q->data[q->tail & 15u] = v;
    q->tail++;
    return 0;
}

int spsc16_pop(spsc_ring16_t *q, uint64_t *out) {
    if (q->head == q->tail) return -1;
    *out = q->data[q->head & 15u];
    q->head++;
    return 0;
}
