#ifndef BRENT_POLLARD_FACTOR_C11_TYPES_H
#define BRENT_POLLARD_FACTOR_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t factor;
    uint32_t steps;
} brent_factor_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} brent_pollard_factor_c11_meta_t;

#endif /* BRENT_POLLARD_FACTOR_C11_TYPES_H */
