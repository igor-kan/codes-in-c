#include "interface.h"
#include <assert.h>

int main(void) {
    uint32_t a[12] = {0xDEAD0001U, 5U, 0xFFFFFFFFU, 0U, 999999U, 42U, 0xDEAD0000U, 5U, 100U, 20U, 7U, 1U};
    assert(msd_radix_sort(a, 12, (msd_config_t){4}) == RADIX_SORT_MSD_C11_OK);
    assert(msd_verify_sorted(a, 12) == RADIX_SORT_MSD_C11_OK);
    assert(a[0] == 0U && a[11] == 0xFFFFFFFFU);
    return 0;
}
