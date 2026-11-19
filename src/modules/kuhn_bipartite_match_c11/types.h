#ifndef KUHN_BIPARTITE_MATCH_C11_TYPES_H
#define KUHN_BIPARTITE_MATCH_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int match_size;
    int match_r[32];
} kuhn_res_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} kuhn_bipartite_match_c11_meta_t;

#endif /* KUHN_BIPARTITE_MATCH_C11_TYPES_H */
