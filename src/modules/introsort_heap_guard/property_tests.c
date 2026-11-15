#include "interface.h"
#include <assert.h>
#include <stdint.h>

int main(void) {
    double buf[256];
    uint32_t rng = 0x98765432U;
    for (int t = 0; t < 15; ++t) {
        size_t n = (size_t)(17 * t + 11);
        for (size_t i = 0; i < n; ++i) {
            rng = rng * 1664525U + 1013904223U;
            buf[i] = (double)(int32_t)(rng % 10000U) * 0.25;
        }
        assert(introsort_heap_guard_sort(buf, n, NULL) == INTROSORT_HEAP_GUARD_OK);
        assert(introsort_heap_guard_verify(buf, n) == INTROSORT_HEAP_GUARD_OK);
    }
    return 0;
}
