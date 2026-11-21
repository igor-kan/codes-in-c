#ifndef LZ77_SLIDING_MATCH_C11_TYPES_H
#define LZ77_SLIDING_MATCH_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t offset;
    uint16_t length;
    uint8_t next_char;
} lz77_token_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} lz77_sliding_match_c11_meta_t;

#endif /* LZ77_SLIDING_MATCH_C11_TYPES_H */
