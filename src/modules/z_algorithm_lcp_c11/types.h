#ifndef Z_ALGORITHM_LCP_C11_TYPES_H
#define Z_ALGORITHM_LCP_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t match_count;
    size_t first_pos;
} z_scan_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} z_algorithm_lcp_c11_meta_t;

#endif /* Z_ALGORITHM_LCP_C11_TYPES_H */
