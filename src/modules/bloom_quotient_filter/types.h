#ifndef BLOOM_QUOTIENT_FILTER_TYPES_H
#define BLOOM_QUOTIENT_FILTER_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define QF_Q_BITS 8
#define QF_R_BITS 8
#define QF_SLOTS (1U << QF_Q_BITS)

typedef struct {
    bool occupied[QF_SLOTS];
    uint16_t rem[QF_SLOTS];
    bool present[QF_SLOTS];
    size_t count;
} quotient_filter_t;

#endif /* BLOOM_QUOTIENT_FILTER_TYPES_H */
