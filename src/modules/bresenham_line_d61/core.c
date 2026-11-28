#include "interface.h"
#include <math.h>
#include <string.h>

size_t bresenham_line(int32_t x0, int32_t y0, int32_t x1, int32_t y1, bres_line_t* out) {
    if (out == NULL) return 0;
    out->count = 0;
    int32_t dx = x1 - x0;
    if (dx < 0) dx = -dx;
    int32_t sx = (x0 < x1) ? 1 : -1;
    int32_t dy = y1 - y0;
    if (dy < 0) dy = -dy;
    int32_t sy = (y0 < y1) ? 1 : -1;
    int32_t err = dx - dy;
    for (;;) {
        if (out->count >= (size_t)BRESENHAM_MAX_POINTS) break;
        out->pts[out->count].x = x0;
        out->pts[out->count].y = y0;
        out->count += 1;
        if (x0 == x1 && y0 == y1) break;
        int32_t e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    return out->count;
}
