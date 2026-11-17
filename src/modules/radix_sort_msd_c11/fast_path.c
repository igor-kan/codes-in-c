#include "interface.h"

void msd_fast_insertion(uint32_t* arr, size_t n) {
    for (size_t i = 1; i < n; ++i) {
        uint32_t key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}
