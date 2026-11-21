#ifndef SIPHASH_SHORT_MAC_C11_TYPES_H
#define SIPHASH_SHORT_MAC_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t k0;
    uint64_t k1;
} sip_key_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} siphash_short_mac_c11_meta_t;

#endif /* SIPHASH_SHORT_MAC_C11_TYPES_H */
