#ifndef RABIN_FINGERPRINT_GEAR_C_TYPES_H
#define RABIN_FINGERPRINT_GEAR_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t offset;
    size_t length;
} cdc_chunk_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} rabin_fingerprint_gear_c_meta_t;

#endif /* RABIN_FINGERPRINT_GEAR_C_TYPES_H */
