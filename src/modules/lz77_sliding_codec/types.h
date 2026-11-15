#ifndef LZ77_SLIDING_CODEC_TYPES_H
#define LZ77_SLIDING_CODEC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define LZ77_MAX_WINDOW 4096U
#define LZ77_MAX_MATCH 255U
typedef struct {
    uint16_t offset;
    uint8_t length;
    uint8_t next;
    uint8_t has_next;
} lz77_token_t;

#endif /* LZ77_SLIDING_CODEC_TYPES_H */
