#ifndef VARINT_LEB128_CODEC_TYPES_H
#define VARINT_LEB128_CODEC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define LEB128_MAX_BYTES 10U
typedef struct {
    size_t encoded_bytes;
    size_t items_processed;
} leb128_stats_t;

#endif /* VARINT_LEB128_CODEC_TYPES_H */
