#ifndef DELTA_ZIG_FRAME_C11_D57_TYPES_H
#define DELTA_ZIG_FRAME_C11_D57_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t len;
    int64_t prev_step;
} delta_meta_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} delta_zig_frame_c11_d57_meta_t;

#endif /* DELTA_ZIG_FRAME_C11_D57_TYPES_H */
