#ifndef TRIDIAGONAL_THOMAS_C11_TYPES_H
#define TRIDIAGONAL_THOMAS_C11_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t n;
    double max_residual;
} tdma_report_t;

#endif /* TRIDIAGONAL_THOMAS_C11_TYPES_H */
