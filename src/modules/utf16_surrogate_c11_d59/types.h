#ifndef UTF16_SURROGATE_C11_D59_TYPES_H
#define UTF16_SURROGATE_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t units[2];
    size_t count;
} utf16_enc_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} utf16_surrogate_c11_d59_meta_t;

#endif /* UTF16_SURROGATE_C11_D59_TYPES_H */
