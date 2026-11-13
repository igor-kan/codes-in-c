/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for In-Place Quicksort with Median-of-Three Partitioning.
 * Module: quicksort_median_three | Algorithm Family: sorting
 */

#ifndef QUICKSORT_MEDIAN_THREE_INTERFACE_H
#define QUICKSORT_MEDIAN_THREE_INTERFACE_H

#include "types.c"

typedef int (*quicksort_median_three_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct quicksort_median_three_vtable {
    int (*init)(quicksort_median_three_state_t* state, const quicksort_median_three_config_t* cfg);
    int (*execute)(quicksort_median_three_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(quicksort_median_three_state_t* state);
    int (*destroy)(quicksort_median_three_state_t* state);
} quicksort_median_three_vtable_t;

#endif /* QUICKSORT_MEDIAN_THREE_INTERFACE_H */
