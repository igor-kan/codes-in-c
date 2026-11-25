#ifndef CRC32C_CASTAGNOLI_D60_TYPES_H
#define CRC32C_CASTAGNOLI_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t state;
    size_t bytes_fed;
} crc32c_ctx_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} crc32c_castagnoli_d60_meta_t;

#endif /* CRC32C_CASTAGNOLI_D60_TYPES_H */
