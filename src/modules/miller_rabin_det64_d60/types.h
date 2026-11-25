#ifndef MILLER_RABIN_DET64_D60_TYPES_H
#define MILLER_RABIN_DET64_D60_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t candidate;
    bool is_prime;
} prime_probe_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} miller_rabin_det64_d60_meta_t;

#endif /* MILLER_RABIN_DET64_D60_TYPES_H */
