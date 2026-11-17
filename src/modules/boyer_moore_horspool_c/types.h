#ifndef BOYER_MOORE_HORSPOOL_C_TYPES_H
#define BOYER_MOORE_HORSPOOL_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t skip[256];
    size_t pat_len;
} bmh_table_t;

#endif /* BOYER_MOORE_HORSPOOL_C_TYPES_H */
