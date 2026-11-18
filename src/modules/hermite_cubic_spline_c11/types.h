#ifndef HERMITE_CUBIC_SPLINE_C11_TYPES_H
#define HERMITE_CUBIC_SPLINE_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t n;
    double x[64];
    double y[64];
    double m[64];
} pchip_spline_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} hermite_cubic_spline_c11_meta_t;

#endif /* HERMITE_CUBIC_SPLINE_C11_TYPES_H */
