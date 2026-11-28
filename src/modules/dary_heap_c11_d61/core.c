#include "interface.h"
#include <math.h>
#include <string.h>

static void dary_sift_up(dary_heap_t* h, size_t i) {
    while (i > 0) {
        size_t parent = (i - 1) / 4;
        if (h->data[parent] <= h->data[i]) break;
        int64_t t = h->data[parent];
        h->data[parent] = h->data[i];
        h->data[i] = t;
        i = parent;
    }
}
static void dary_sift_down(dary_heap_t* h, size_t i) {
    for (;;) {
        size_t first = 4 * i + 1;
        if (first >= h->size) break;
        size_t last = first + 4;
        if (last > h->size) last = h->size;
        size_t best = first;
        for (size_t c = first + 1; c < last; ++c) {
            if (h->data[c] < h->data[best]) best = c;
        }
        if (h->data[i] <= h->data[best]) break;
        int64_t t = h->data[i];
        h->data[i] = h->data[best];
        h->data[best] = t;
        i = best;
    }
}
void dary_heap_init(dary_heap_t* h) {
    h->size = 0;
}
bool dary_heap_push(dary_heap_t* h, int64_t v) {
    if (h->size >= (size_t)DARY_HEAP_CAP) return false;
    h->data[h->size] = v;
    dary_sift_up(h, h->size);
    h->size += 1;
    return true;
}
bool dary_heap_pop(dary_heap_t* h, int64_t* out) {
    if (h->size == 0) return false;
    *out = h->data[0];
    h->size -= 1;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        dary_sift_down(h, 0);
    }
    return true;
}
bool dary_heap_peek(const dary_heap_t* h, int64_t* out) {
    if (h->size == 0) return false;
    *out = h->data[0];
    return true;
}
