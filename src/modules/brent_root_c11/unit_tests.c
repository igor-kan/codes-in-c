#include "interface.h"
#include <assert.h>
#include <math.h>

static double cubic(double x, void* ctx) { (void)ctx; return x * x * x - x - 2.0; }

int main(void) {
    brent_result_t res;
    assert(brent_solve(cubic, NULL, 1.0, 2.0, 1e-12, 100, &res) == BRENT_ROOT_C11_OK);
    assert(verify_root_residual(&res, 1e-12) == BRENT_ROOT_C11_OK);
    assert(fabs(res.root - 1.5213797068045676) < 1e-10);
    return 0;
}
