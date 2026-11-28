#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(shell_sort_ciura_d61_validate_len(1) == SHELL_SORT_CIURA_D61_OK);
    int64_t a[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 0};
    shell_sort_ciura(a, 10);
    for (size_t i = 1; i < 10; ++i) assert(a[i - 1] <= a[i]);
    assert(a[0] == 0 && a[9] == 9);
    assert(shell_sort_ciura_d61_verify_guard(true) == SHELL_SORT_CIURA_D61_OK);
    return 0;
}
