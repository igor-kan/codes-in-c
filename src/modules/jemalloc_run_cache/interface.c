/**
 * @file interface.c
 * @brief Abstract contracts and operational prototypes for Thread-Cached Run Allocator with Slab Bitmap Binning.
 * Module: jemalloc_run_cache
 */

#ifndef JEMALLOC_RUN_CACHE_INTERFACE_H
#define JEMALLOC_RUN_CACHE_INTERFACE_H

#include "types.c"

typedef int (*jemalloc_run_cache_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct jemalloc_run_cache_vtable {
    int (*init)(jemalloc_run_cache_state_t* state, const jemalloc_run_cache_config_t* cfg);
    int (*execute)(jemalloc_run_cache_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(jemalloc_run_cache_state_t* state);
    int (*destroy)(jemalloc_run_cache_state_t* state);
} jemalloc_run_cache_vtable_t;

#endif /* JEMALLOC_RUN_CACHE_INTERFACE_H */
