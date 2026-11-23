#ifndef VARINT_PREFIX_ENC_C11_D58_TYPES_H
#define VARINT_PREFIX_ENC_C11_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t len;
    uint64_t val;
} pvar_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} varint_prefix_enc_c11_d58_meta_t;

#endif /* VARINT_PREFIX_ENC_C11_D58_TYPES_H */
