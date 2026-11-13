/**
 * @file interface.c
 * @brief Abstract function prototypes and contracts for 64-Bit Aligned Bitwise Bloom Filter with Multi-Hash.
 * Module: bitwise_bloom_filter | Algorithm Family: bloom
 */

#ifndef BITWISE_BLOOM_FILTER_INTERFACE_H
#define BITWISE_BLOOM_FILTER_INTERFACE_H

#include "types.c"

typedef int (*bitwise_bloom_filter_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct bitwise_bloom_filter_vtable {
    int (*init)(bitwise_bloom_filter_state_t* state, const bitwise_bloom_filter_config_t* cfg);
    int (*execute)(bitwise_bloom_filter_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(bitwise_bloom_filter_state_t* state);
    int (*destroy)(bitwise_bloom_filter_state_t* state);
} bitwise_bloom_filter_vtable_t;

#endif /* BITWISE_BLOOM_FILTER_INTERFACE_H */
