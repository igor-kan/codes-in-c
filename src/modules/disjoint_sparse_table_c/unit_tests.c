#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(disjoint_sparse_table_c_validate_len(1) == DISJOINT_SPARSE_TABLE_C_OK);
    int64_t a[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    dst_sum_t dst; dst_build(&dst, a, 8);
    assert(dst_query(&dst, 1, 5) == (1 + 4 + 1 + 5 + 9));
    assert(dst_query(&dst, 0, 7) == 31);
    assert(disjoint_sparse_table_c_verify_guard(true) == DISJOINT_SPARSE_TABLE_C_OK);
    return 0;
}
