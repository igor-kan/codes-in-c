#ifndef FLOYD_STEINBERG_DITHER_D61_TYPES_H
#define FLOYD_STEINBERG_DITHER_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define FLOYD_MAX_PIXELS 4096
typedef struct {
    size_t width;
    size_t height;
    size_t pixels;
} floyd_image_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} floyd_steinberg_dither_d61_meta_t;

#endif /* FLOYD_STEINBERG_DITHER_D61_TYPES_H */
