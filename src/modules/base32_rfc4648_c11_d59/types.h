#ifndef BASE32_RFC4648_C11_D59_TYPES_H
#define BASE32_RFC4648_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t enc_len;
    int valid;
} base32_meta_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} base32_rfc4648_c11_d59_meta_t;

#endif /* BASE32_RFC4648_C11_D59_TYPES_H */
