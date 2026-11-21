#ifndef CRC32C_CASTAGNOLI_C11_TYPES_H
#define CRC32C_CASTAGNOLI_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t digest;
    size_t byte_len;
} crc32c_result_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} crc32c_castagnoli_c11_meta_t;

#endif /* CRC32C_CASTAGNOLI_C11_TYPES_H */
