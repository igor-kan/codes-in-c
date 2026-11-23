#ifndef CRC32_IEEE8023_C11_D58_TYPES_H
#define CRC32_IEEE8023_C11_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t crc;
    size_t len;
} ieee_crc32_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} crc32_ieee8023_c11_d58_meta_t;

#endif /* CRC32_IEEE8023_C11_D58_TYPES_H */
