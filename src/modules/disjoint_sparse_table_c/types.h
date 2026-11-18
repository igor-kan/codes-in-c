#ifndef DISJOINT_SPARSE_TABLE_C_TYPES_H
#define DISJOINT_SPARSE_TABLE_C_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define DST_LOG 6
#define DST_MAX (1 << DST_LOG)
typedef struct {
    int32_t n;
    int32_t levels;
    int64_t table[DST_LOG + 1][DST_MAX];
} dst_sum_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} disjoint_sparse_table_c_meta_t;

#endif /* DISJOINT_SPARSE_TABLE_C_TYPES_H */
