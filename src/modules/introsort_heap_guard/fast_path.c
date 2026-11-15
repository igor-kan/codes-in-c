#include "interface.h"

void introsort_heap_guard_insertion_fast(double* arr, size_t n) {
    if (!arr || n < 2) return;
    for (size_t i = 1; i < n; ++i) {
        double key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
