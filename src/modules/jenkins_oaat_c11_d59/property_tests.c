#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(jenkins_oaat_c11_d59_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    const uint8_t x[2] = {1, 2}, y[2] = {2, 1};
    assert(jenkins_oaat32(x, 2) != jenkins_oaat32(y, 2));
    return 0;
}
