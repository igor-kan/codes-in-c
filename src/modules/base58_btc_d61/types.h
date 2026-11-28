#ifndef BASE58_BTC_D61_TYPES_H
#define BASE58_BTC_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BASE58_MAX_IN 64
#define BASE58_MAX_OUT 96
typedef struct {
    char text[BASE58_MAX_OUT];
    size_t length;
} base58_string_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} base58_btc_d61_meta_t;

#endif /* BASE58_BTC_D61_TYPES_H */
