#include "interface.h"

disjoint_sparse_table_c_err_t disjoint_sparse_table_c_validate_len(size_t n) {
    if (n == 0) {
        return DISJOINT_SPARSE_TABLE_C_ERR_INVALID;
    }
    return DISJOINT_SPARSE_TABLE_C_OK;
}
