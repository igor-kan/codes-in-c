#ifndef RESERVOIR_R_SKIP_C11_TYPES_H
#define RESERVOIR_R_SKIP_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t selected[8];
    size_t count;
} reservoir8_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} reservoir_r_skip_c11_meta_t;

#endif /* RESERVOIR_R_SKIP_C11_TYPES_H */
