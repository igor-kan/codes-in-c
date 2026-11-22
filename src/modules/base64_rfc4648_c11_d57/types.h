#ifndef BASE64_RFC4648_C11_D57_TYPES_H
#define BASE64_RFC4648_C11_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t encoded_bytes;
    size_t decoded_bytes;
} base64_stats_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} base64_rfc4648_c11_d57_meta_t;

#endif /* BASE64_RFC4648_C11_D57_TYPES_H */
