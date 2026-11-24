#ifndef PEARSON_R_CORR_C11_D59_TYPES_H
#define PEARSON_R_CORR_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint64_t count;
    double mean;
    double m2;
} welford_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} pearson_r_corr_c11_d59_meta_t;

#endif /* PEARSON_R_CORR_C11_D59_TYPES_H */
