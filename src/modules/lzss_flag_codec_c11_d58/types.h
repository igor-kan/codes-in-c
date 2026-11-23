#ifndef LZSS_FLAG_CODEC_C11_D58_TYPES_H
#define LZSS_FLAG_CODEC_C11_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t is_match;
    uint8_t val_or_off;
    uint8_t len;
} lzss_op_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} lzss_flag_codec_c11_d58_meta_t;

#endif /* LZSS_FLAG_CODEC_C11_D58_TYPES_H */
