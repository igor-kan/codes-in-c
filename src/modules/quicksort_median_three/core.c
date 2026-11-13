/**
 * @file core.c
 * @brief Median-of-three in-place quicksort partitioning for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three
 */

#include "types.c"

static inline void quicksort_median_three_swap(double* a, double* b) {
    double t = *a; *a = *b; *b = t;
}

static size_t quicksort_median_three_partition(double* arr, size_t low, size_t high) {
    double pivot = arr[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            quicksort_median_three_swap(&arr[i], &arr[j]);
            i++;
        }
    }
    quicksort_median_three_swap(&arr[i], &arr[high]);
    return i;
}

void quicksort_median_three_sort(double* arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = quicksort_median_three_partition(arr, low, high);
        if (pi > low) quicksort_median_three_sort(arr, low, pi - 1);
        quicksort_median_three_sort(arr, pi + 1, high);
    }
}
