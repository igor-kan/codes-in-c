#ifndef BRESENHAM_LINE_D61_TYPES_H
#define BRESENHAM_LINE_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BRESENHAM_MAX_POINTS 128
typedef struct {
    int32_t x;
    int32_t y;
} bres_point_t;

typedef struct {
    bres_point_t pts[BRESENHAM_MAX_POINTS];
    size_t count;
} bres_line_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} bresenham_line_d61_meta_t;

#endif /* BRESENHAM_LINE_D61_TYPES_H */
