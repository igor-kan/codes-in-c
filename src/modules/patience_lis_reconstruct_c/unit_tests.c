#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(patience_lis_reconstruct_c_validate_len(1) == PATIENCE_LIS_RECONSTRUCT_C_OK);
    int64_t a[8] = {10, 9, 2, 5, 3, 7, 101, 18};
    lis_result_t r;
    assert(patience_lis(a, 8, &r) == 4);
    for (size_t i = 1; i < r.length; ++i) assert(r.seq[i - 1] < r.seq[i]);
    assert(patience_lis_reconstruct_c_verify_guard(true) == PATIENCE_LIS_RECONSTRUCT_C_OK);
    return 0;
}
