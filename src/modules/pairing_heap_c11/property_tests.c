#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t a[32], b[32];
    for (size_t i = 0; i < 32; ++i) {
        a[i] = (int64_t)((i * 19 + 7) % 32);
        b[i] = (int64_t)(31 - i);
    }
    ph_parallel_sort_pair(a, 32, b, 32);
    for (size_t i = 1; i < 32; ++i) {
        assert(a[i - 1] <= a[i]);
        assert(b[i - 1] <= b[i]);
    }
    return 0;
}
