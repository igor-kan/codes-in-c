#ifndef TIMSORT_MERGE_GALLOP_TYPES_H
#define TIMSORT_MERGE_GALLOP_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TIMSORT_MINRUN 16U
typedef struct {
    size_t base;
    size_t len;
} tim_run_t;

#endif /* TIMSORT_MERGE_GALLOP_TYPES_H */
