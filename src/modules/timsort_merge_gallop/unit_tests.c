#include "interface.h"
#include <assert.h>

int main(void) {
    int64_t a[12] = {42, -5, 19, 19, 0, -100, 77, 3, 2, 1, 88, 7};
    assert(timsort_merge_gallop_sort(a, 12) == TIMSORT_MERGE_GALLOP_OK);
    assert(timsort_merge_gallop_verify_sorted(a, 12) == TIMSORT_MERGE_GALLOP_OK);
    assert(a[0] == -100 && a[1] == -5 && a[11] == 88);
    assert(timsort_merge_gallop_right(19, a, 12) == 9);
    return 0;
}
