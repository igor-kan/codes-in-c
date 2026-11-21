#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(reservoir_r_skip_c11_validate_len(1) == RESERVOIR_R_SKIP_C11_OK);
    size_t res[4];
    size_t m = reservoir_sample_u64(100, 4, 42ULL, res);
    assert(m == 4);
    for (size_t i = 0; i < 4; ++i) {
        assert(res[i] < 100);
        for (size_t j = i + 1; j < 4; ++j) assert(res[i] != res[j]);
    }
    assert(reservoir_r_skip_c11_verify_guard(true) == RESERVOIR_R_SKIP_C11_OK);
    return 0;
}
