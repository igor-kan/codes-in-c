#ifndef STOER_WAGNER_MINCUT_C11_TYPES_H
#define STOER_WAGNER_MINCUT_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int64_t min_cut;
    int32_t phases;
} sw_cut_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} stoer_wagner_mincut_c11_meta_t;

#endif /* STOER_WAGNER_MINCUT_C11_TYPES_H */
