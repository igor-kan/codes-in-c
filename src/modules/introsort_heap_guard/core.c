#include "interface.h"
#include <math.h>

static void swap_d(double* a, double* b) { double t = *a; *a = *b; *b = t; }

static void sift_down(double* a, size_t base, size_t root, size_t n) {
    while (2 * root + 1 < n) {
        size_t child = 2 * root + 1;
        size_t sw = root;
        if (a[base + sw] < a[base + child]) sw = child;
        if (child + 1 < n && a[base + sw] < a[base + child + 1]) sw = child + 1;
        if (sw == root) return;
        swap_d(&a[base + root], &a[base + sw]);
        root = sw;
    }
}

void introsort_heap_guard_heapsort(double* arr, size_t lo, size_t hi) {
    size_t n = hi - lo;
    if (n < 2) return;
    for (size_t i = n / 2; i > 0; --i) sift_down(arr, lo, i - 1, n);
    for (size_t end = n - 1; end > 0; --end) {
        swap_d(&arr[lo], &arr[lo + end]);
        sift_down(arr, lo, 0, end);
    }
}

static size_t partition_m3(double* a, size_t lo, size_t hi) {
    size_t mid = lo + (hi - lo) / 2;
    size_t last = hi - 1;
    if (a[mid] < a[lo]) swap_d(&a[mid], &a[lo]);
    if (a[last] < a[lo]) swap_d(&a[last], &a[lo]);
    if (a[mid] < a[last]) swap_d(&a[mid], &a[last]);
    double pivot = a[last];
    size_t i = lo;
    for (size_t j = lo; j < last; ++j) {
        if (a[j] <= pivot) { swap_d(&a[i], &a[j]); i++; }
    }
    swap_d(&a[i], &a[last]);
    return i;
}

static void intro_rec(double* a, size_t lo, size_t hi, int depth, introsort_metrics_t* m) {
    while (hi - lo > INTRO_INSERT_THRESH) {
        if (depth == 0) {
            if (m) m->heap_fallbacks++;
            introsort_heap_guard_heapsort(a, lo, hi);
            return;
        }
        depth--;
        size_t p = partition_m3(a, lo, hi);
        if (m) m->comparisons += (hi - lo);
        if (p - lo < hi - p) {
            intro_rec(a, lo, p, depth, m);
            lo = p + 1;
        } else {
            intro_rec(a, p + 1, hi, depth, m);
            hi = p;
        }
    }
}

introsort_heap_guard_err_t introsort_heap_guard_sort(double* arr, size_t n, introsort_metrics_t* m) {
    introsort_heap_guard_err_t v = introsort_heap_guard_validate(arr, n);
    if (v != INTROSORT_HEAP_GUARD_OK) return v;
    if (m) { m->comparisons = 0; m->swaps = 0; m->heap_fallbacks = 0; }
    if (n < 2) return INTROSORT_HEAP_GUARD_OK;
    int max_depth = 0;
    for (size_t x = n; x > 1; x >>= 1) max_depth += 2;
    intro_rec(arr, 0, n, max_depth, m);
    for (size_t i = 1; i < n; ++i) {
        double key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) { arr[j] = arr[j - 1]; j--; }
        arr[j] = key;
    }
    return INTROSORT_HEAP_GUARD_OK;
}
