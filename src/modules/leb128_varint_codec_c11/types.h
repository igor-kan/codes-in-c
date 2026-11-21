#ifndef LEB128_VARINT_CODEC_C11_TYPES_H
#define LEB128_VARINT_CODEC_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t bytes_written;
    uint64_t decoded;
} varint_trace_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} leb128_varint_codec_c11_meta_t;

#endif /* LEB128_VARINT_CODEC_C11_TYPES_H */
