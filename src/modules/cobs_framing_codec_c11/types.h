#ifndef COBS_FRAMING_CODEC_C11_TYPES_H
#define COBS_FRAMING_CODEC_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t encoded_len;
    int status;
} cobs_meta_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} cobs_framing_codec_c11_meta_t;

#endif /* COBS_FRAMING_CODEC_C11_TYPES_H */
