#ifndef MURMUR3_32_FOLD_C11_D57_TYPES_H
#define MURMUR3_32_FOLD_C11_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t seed;
    uint32_t hash;
} murmur32_out_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} murmur3_32_fold_c11_d57_meta_t;

#endif /* MURMUR3_32_FOLD_C11_D57_TYPES_H */
