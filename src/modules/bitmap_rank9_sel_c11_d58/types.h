#ifndef BITMAP_RANK9_SEL_C11_D58_TYPES_H
#define BITMAP_RANK9_SEL_C11_D58_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t word;
    int ones;
} bitword_meta_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} bitmap_rank9_sel_c11_d58_meta_t;

#endif /* BITMAP_RANK9_SEL_C11_D58_TYPES_H */
