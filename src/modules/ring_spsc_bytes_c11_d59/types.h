#ifndef RING_SPSC_BYTES_C11_D59_TYPES_H
#define RING_SPSC_BYTES_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t buf[64];
    size_t head;
    size_t tail;
    size_t used;
} byte_ring64_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} ring_spsc_bytes_c11_d59_meta_t;

#endif /* RING_SPSC_BYTES_C11_D59_TYPES_H */
