/**
 * @file interface.c
 * @brief Abstract contracts and prototypes for 64-Bit Word Compact Bitset with Popcount.
 * Module: compact_bitset
 */

#ifndef COMPACT_BITSET_INTERFACE_H
#define COMPACT_BITSET_INTERFACE_H

#include "types.c"

typedef int (*compact_bitset_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct compact_bitset_vtable {
    int (*init)(compact_bitset_state_t* state, const compact_bitset_config_t* cfg);
    int (*execute)(compact_bitset_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(compact_bitset_state_t* state);
} compact_bitset_vtable_t;

#endif /* COMPACT_BITSET_INTERFACE_H */
