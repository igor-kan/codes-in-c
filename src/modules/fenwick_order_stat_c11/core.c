#include "interface.h"
#include <math.h>
#include <string.h>

void os_init(os_fenwick_t* f, int n) { memset(f->bit, 0, sizeof(f->bit)); f->n = n; }
void os_add(os_fenwick_t* f, int idx, int64_t delta) {
    for (int i = idx + 1; i <= f->n; i += i & -i) f->bit[i] += delta;
}
int os_kth(const os_fenwick_t* f, int64_t k) {
    int pos = 0;
    for (int pw = 32; pw > 0; pw >>= 1) {
        if (pos + pw <= f->n && f->bit[pos + pw] < k) {
            pos += pw;
            k -= f->bit[pos];
        }
    }
    return pos;
}
