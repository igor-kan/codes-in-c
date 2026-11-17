#include "interface.h"

void ph_fast_sort(int64_t* arr, size_t n) {
    pairing_heap_t h;
    ph_init(&h);
    for (size_t i = 0; i < n && i < PH_MAX_NODES; ++i) ph_push(&h, arr[i], (int32_t)i, NULL);
    for (size_t i = 0; i < n && i < PH_MAX_NODES; ++i) ph_pop_min(&h, &arr[i], NULL);
}
