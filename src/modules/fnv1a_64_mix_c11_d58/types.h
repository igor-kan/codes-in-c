#ifndef FNV1A_64_MIX_C11_D58_TYPES_H
#define FNV1A_64_MIX_C11_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t state;
} fnv1a_stream_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} fnv1a_64_mix_c11_d58_meta_t;

#endif /* FNV1A_64_MIX_C11_D58_TYPES_H */
