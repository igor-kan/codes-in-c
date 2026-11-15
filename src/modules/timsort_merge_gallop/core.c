#include "interface.h"
#include <stdlib.h>
#include <string.h>

static void binary_ins_sort(int64_t* a, size_t lo, size_t hi, size_t start) {
    if (start == lo) start++;
    for (; start < hi; ++start) {
        int64_t pivot = a[start];
        size_t l = lo, r = start;
        while (l < r) {
            size_t m = l + (r - l) / 2;
            if (pivot < a[m]) r = m;
            else l = m + 1;
        }
        memmove(a + l + 1, a + l, (start - l) * sizeof(int64_t));
        a[l] = pivot;
    }
}

size_t timsort_merge_gallop_right(int64_t key, const int64_t* a, size_t len) {
    if (len == 0 || key < a[0]) return 0;
    size_t ofs = 1, last_ofs = 0;
    while (ofs < len && a[ofs] <= key) {
        last_ofs = ofs;
        ofs = (ofs << 1) + 1;
    }
    if (ofs > len) ofs = len;
    size_t l = last_ofs + 1, r = ofs;
    while (l < r) {
        size_t m = l + (r - l) / 2;
        if (key < a[m]) r = m;
        else l = m + 1;
    }
    return r;
}

static void merge_adjacent(int64_t* a, size_t lo, size_t mid, size_t hi, int64_t* tmp) {
    size_t n1 = mid - lo;
    memcpy(tmp, a + lo, n1 * sizeof(int64_t));
    size_t i = 0, j = mid, k = lo;
    while (i < n1 && j < hi) {
        if (tmp[i] <= a[j]) a[k++] = tmp[i++];
        else a[k++] = a[j++];
    }
    while (i < n1) a[k++] = tmp[i++];
}

timsort_merge_gallop_err_t timsort_merge_gallop_sort(int64_t* arr, size_t n) {
    if (n > 0 && !arr) return TIMSORT_MERGE_GALLOP_ERR_NULL;
    if (n < 2) return TIMSORT_MERGE_GALLOP_OK;
    int64_t* tmp = (int64_t*)malloc(n * sizeof(int64_t));
    tim_run_t* runs = (tim_run_t*)malloc((n / TIMSORT_MINRUN + 8) * sizeof(tim_run_t));
    if (!tmp || !runs) { free(tmp); free(runs); return TIMSORT_MERGE_GALLOP_ERR_BOUNDS; }

    size_t nruns = 0, lo = 0;
    while (lo < n) {
        size_t hi = lo + 1;
        if (hi < n) {
            if (arr[hi] < arr[lo]) {
                while (hi < n && arr[hi] < arr[hi - 1]) hi++;
                for (size_t l = lo, r = hi - 1; l < r; ++l, --r) {
                    int64_t t = arr[l]; arr[l] = arr[r]; arr[r] = t;
                }
            } else {
                while (hi < n && arr[hi] >= arr[hi - 1]) hi++;
            }
        }
        size_t run_len = hi - lo;
        if (run_len < TIMSORT_MINRUN) {
            size_t force = (n - lo < TIMSORT_MINRUN) ? (n - lo) : TIMSORT_MINRUN;
            binary_ins_sort(arr, lo, lo + force, lo + run_len);
            run_len = force;
        }
        runs[nruns++] = (tim_run_t){lo, run_len};
        lo += run_len;
        while (nruns > 1) {
            size_t b = nruns - 2;
            if ((b > 0 && runs[b - 1].len <= runs[b].len + runs[b + 1].len) ||
                runs[b].len <= runs[b + 1].len) {
                merge_adjacent(arr, runs[b].base, runs[b + 1].base, runs[b + 1].base + runs[b + 1].len, tmp);
                runs[b].len += runs[b + 1].len;
                nruns--;
            } else {
                break;
            }
        }
    }
    while (nruns > 1) {
        size_t b = nruns - 2;
        merge_adjacent(arr, runs[b].base, runs[b + 1].base, runs[b + 1].base + runs[b + 1].len, tmp);
        runs[b].len += runs[b + 1].len;
        nruns--;
    }
    free(tmp);
    free(runs);
    return TIMSORT_MERGE_GALLOP_OK;
}
