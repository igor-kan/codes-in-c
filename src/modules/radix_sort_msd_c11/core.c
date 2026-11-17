#include "interface.h"

static void msd_recurse(uint32_t* arr, size_t lo, size_t hi, int byte_idx, uint32_t cutoff) {
    if (hi <= lo + 1 || byte_idx < 0) return;
    if (hi - lo <= cutoff) {
        msd_fast_insertion(arr + lo, hi - lo);
        return;
    }
    int shift = byte_idx * 8;
    size_t count[256] = {0};
    for (size_t i = lo; i < hi; ++i) count[(arr[i] >> shift) & 0xFFU]++;
    size_t start[256], next_pos[256];
    size_t acc = lo;
    for (int b = 0; b < 256; ++b) {
        start[b] = acc;
        next_pos[b] = acc;
        acc += count[b];
    }
    for (int b = 0; b < 256; ++b) {
        size_t end_b = start[b] + count[b];
        while (next_pos[b] < end_b) {
            uint32_t v = arr[next_pos[b]];
            uint32_t bucket = (v >> shift) & 0xFFU;
            if ((int)bucket == b) {
                next_pos[b]++;
            } else {
                size_t dst = next_pos[bucket]++;
                uint32_t tmp = arr[dst];
                arr[dst] = v;
                arr[next_pos[b]] = tmp;
            }
        }
    }
    for (int b = 0; b < 256; ++b) {
        if (count[b] > 1) msd_recurse(arr, start[b], start[b] + count[b], byte_idx - 1, cutoff);
    }
}

radix_sort_msd_c11_err_t msd_radix_sort(uint32_t* arr, size_t n, msd_config_t cfg) {
    radix_sort_msd_c11_err_t err = msd_validate_slice(arr, n);
    if (err != RADIX_SORT_MSD_C11_OK) return err;
    msd_recurse(arr, 0, n, 3, cfg.insertion_cutoff < 2 ? 16 : cfg.insertion_cutoff);
    return RADIX_SORT_MSD_C11_OK;
}
