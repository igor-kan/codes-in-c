#ifndef SHELL_SORT_CIURA_D61_TYPES_H
#define SHELL_SORT_CIURA_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SHELL_MAX_GAPS 9
typedef struct {
    int64_t value[SHELL_MAX_GAPS];
    size_t count;
} shell_gap_table_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} shell_sort_ciura_d61_meta_t;

#endif /* SHELL_SORT_CIURA_D61_TYPES_H */
