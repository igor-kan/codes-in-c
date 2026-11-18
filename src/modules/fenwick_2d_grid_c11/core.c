#include "interface.h"
#include <math.h>
#include <string.h>

void fw2d_init(fenwick2d_t* f, int32_t rows, int32_t cols) {
    memset(f, 0, sizeof(*f));
    f->rows = rows; f->cols = cols;
}
void fw2d_add(fenwick2d_t* f, int32_t r, int32_t c, int64_t delta) {
    for (int32_t i = r + 1; i <= f->rows; i += i & -i) {
        for (int32_t j = c + 1; j <= f->cols; j += j & -j) f->bit[i][j] += delta;
    }
}
int64_t fw2d_prefix(const fenwick2d_t* f, int32_t r, int32_t c) {
    int64_t s = 0;
    for (int32_t i = r + 1; i > 0; i -= i & -i) {
        for (int32_t j = c + 1; j > 0; j -= j & -j) s += f->bit[i][j];
    }
    return s;
}
int64_t fw2d_rect_sum(const fenwick2d_t* f, int32_t r1, int32_t c1, int32_t r2, int32_t c2) {
    return fw2d_prefix(f, r2, c2) - fw2d_prefix(f, r1 - 1, c2) - fw2d_prefix(f, r2, c1 - 1) + fw2d_prefix(f, r1 - 1, c1 - 1);
}
