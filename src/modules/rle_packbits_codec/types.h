#ifndef RLE_PACKBITS_CODEC_TYPES_H
#define RLE_PACKBITS_CODEC_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t compressed_bytes;
    size_t run_count;
} packbits_stats_t;

#endif /* RLE_PACKBITS_CODEC_TYPES_H */
