#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    uint64_t _pa[2] = {11ULL, 22ULL}, _pb[2] = {33ULL, 44ULL};
    assert(xor_linked_list_d61_parallel_fold_pair(_pa, 2, _pb, 2) != 0ULL);
    xor_list_t xl; xor_list_init(&xl);
    for (int i = 0; i < 20; ++i) assert(xor_list_push_back(&xl, (int64_t)(i * 3)));
    int64_t vals[24];
    size_t n = xor_list_forward(&xl, vals, 24);
    assert(n == 20);
    for (size_t i = 0; i < n; ++i) assert(vals[i] == (int64_t)(i * 3));
    return 0;
}
