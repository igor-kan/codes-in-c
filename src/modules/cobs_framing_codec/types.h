#ifndef COBS_FRAMING_CODEC_TYPES_H
#define COBS_FRAMING_CODEC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t encoded_len;
    size_t decoded_len;
} cobs_metrics_t;

#endif /* COBS_FRAMING_CODEC_TYPES_H */
