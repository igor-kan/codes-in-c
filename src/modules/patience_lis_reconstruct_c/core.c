#include "interface.h"
#include <math.h>
#include <string.h>

size_t patience_lis(const int64_t* arr, size_t n, lis_result_t* out) {
    size_t tail_idx[128];
    int32_t prev[128];
    size_t len = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t lo = 0, hi = len;
        while (lo < hi) {
            size_t mid = (lo + hi) >> 1;
            if (arr[tail_idx[mid]] < arr[i]) lo = mid + 1;
            else hi = mid;
        }
        tail_idx[lo] = i;
        prev[i] = (lo > 0) ? (int32_t)tail_idx[lo - 1] : -1;
        if (lo == len) ++len;
    }
    out->length = len;
    int32_t cur = len > 0 ? (int32_t)tail_idx[len - 1] : -1;
    for (size_t k = len; k-- > 0;) {
        out->seq[k] = arr[cur];
        cur = prev[cur];
    }
    return len;
}
