#include "interface.h"
#include <math.h>
#include <string.h>

void delta_encode(const int64_t *src, size_t n, int64_t *deltas) {
    if (n == 0) return;
    deltas[0] = src[0];
    if (n == 1) return;
    int64_t prev_d = src[1] - src[0];
    deltas[1] = prev_d;
    for (size_t i = 2; i < n; ++i) {
        int64_t d = src[i] - src[i - 1];
        deltas[i] = d - prev_d;
        prev_d = d;
    }
}

void delta_decode(const int64_t *deltas, size_t n, int64_t *dst) {
    if (n == 0) return;
    dst[0] = deltas[0];
    if (n == 1) return;
    int64_t prev_d = deltas[1];
    dst[1] = dst[0] + prev_d;
    for (size_t i = 2; i < n; ++i) {
        int64_t d = prev_d + deltas[i];
        dst[i] = dst[i - 1] + d;
        prev_d = d;
    }
}
