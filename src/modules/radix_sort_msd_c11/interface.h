#ifndef RADIX_SORT_MSD_C11_INTERFACE_H
#define RADIX_SORT_MSD_C11_INTERFACE_H

#include "types.h"
#include "errors.h"

radix_sort_msd_c11_err_t msd_radix_sort(uint32_t* arr, size_t n, msd_config_t cfg);
radix_sort_msd_c11_err_t msd_validate_slice(const uint32_t* arr, size_t n);
void msd_fast_insertion(uint32_t* arr, size_t n);
void msd_parallel_sort_halves(uint32_t* a, size_t na, uint32_t* b, size_t nb);
radix_sort_msd_c11_err_t msd_verify_sorted(const uint32_t* arr, size_t n);

#endif /* RADIX_SORT_MSD_C11_INTERFACE_H */
