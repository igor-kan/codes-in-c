#include "interface.h"

disjoint_sparse_table_c_err_t disjoint_sparse_table_c_verify_guard(bool cond) {
    if (!cond) {
        return DISJOINT_SPARSE_TABLE_C_ERR_INVARIANT;
    }
    return DISJOINT_SPARSE_TABLE_C_OK;
}
