#include "interface.h"
#include <math.h>
#include <string.h>

void shell_sort_ciura(int64_t* a, size_t n) {
    static const size_t gaps[SHELL_MAX_GAPS] = {1750U, 701U, 301U, 132U, 57U, 23U, 10U, 4U, 1U};
    for (size_t gi = 0; gi < SHELL_MAX_GAPS; ++gi) {
        size_t gap = gaps[gi];
        if (gap >= n) continue;
        for (size_t i = gap; i < n; ++i) {
            int64_t tmp = a[i];
            size_t j = i;
            while (j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}
