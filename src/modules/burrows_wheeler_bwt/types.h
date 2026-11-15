#ifndef BURROWS_WHEELER_BWT_TYPES_H
#define BURROWS_WHEELER_BWT_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t primary_index;
    size_t length;
} bwt_header_t;

#endif /* BURROWS_WHEELER_BWT_TYPES_H */
