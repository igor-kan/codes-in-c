#ifndef GOLOMB_RICE_C11_D59_TYPES_H
#define GOLOMB_RICE_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t bit_len;
    uint32_t k_param;
} gr_code_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} golomb_rice_c11_d59_meta_t;

#endif /* GOLOMB_RICE_C11_D59_TYPES_H */
