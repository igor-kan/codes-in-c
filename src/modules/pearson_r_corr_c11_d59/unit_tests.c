#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(pearson_r_corr_c11_d59_validate_len(1) == PEARSON_R_CORR_C11_D59_OK);
    welford_t w; welford_init(&w);
    const double xs[4] = {1e9 + 1.0, 1e9 + 2.0, 1e9 + 3.0, 1e9 + 4.0};
    for (int i = 0; i < 4; ++i) welford_add(&w, xs[i]);
    double v = welford_var(&w);
    assert(v > 1.66 && v < 1.67);
    assert(pearson_r_corr_c11_d59_verify_guard(true) == PEARSON_R_CORR_C11_D59_OK);
    return 0;
}
