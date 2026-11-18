#include "interface.h"
#include <math.h>
#include <string.h>

void dst_build(dst_sum_t* d, const int64_t* arr, int32_t n) {
    memset(d, 0, sizeof(*d));
    int32_t p2 = 1, lv = 0;
    while (p2 < n) { p2 <<= 1; ++lv; }
    d->n = p2; d->levels = lv;
    for (int32_t i = 0; i < n; ++i) d->table[0][i] = arr[i];
    for (int32_t h = 1; h <= lv; ++h) {
        int32_t half = 1 << (h - 1), blk = half << 1;
        for (int32_t mid = half; mid < p2; mid += blk) {
            d->table[h][mid - 1] = d->table[0][mid - 1];
            for (int32_t i = mid - 2; i >= mid - half; --i) d->table[h][i] = d->table[h][i + 1] + d->table[0][i];
            d->table[h][mid] = d->table[0][mid];
            for (int32_t i = mid + 1; i < mid + half; ++i) d->table[h][i] = d->table[h][i - 1] + d->table[0][i];
        }
    }
}
int64_t dst_query(const dst_sum_t* d, int32_t l, int32_t r) {
    if (l == r) return d->table[0][l];
    uint32_t x = (uint32_t)(l ^ r);
    int32_t h = 32 - __builtin_clz(x);
    return d->table[h][l] + d->table[h][r];
}
