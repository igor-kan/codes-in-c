#ifndef LZ77_WINDOW_MATCH_D60_TYPES_H
#define LZ77_WINDOW_MATCH_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t dist;
    uint16_t len;
    uint8_t next_ch;
} lz77_tok_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} lz77_window_match_d60_meta_t;

#endif /* LZ77_WINDOW_MATCH_D60_TYPES_H */
