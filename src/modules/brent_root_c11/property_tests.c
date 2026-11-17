#include "interface.h"
#include <assert.h>
#include <math.h>

static double cos_eq(double x, void* ctx) { (void)ctx; return cos(x) - x; }

int main(void) {
    double br[4] = {0.0, 1.5, -0.5, 2.0};
    brent_result_t out[2];
    brent_parallel_solve(cos_eq, br, 2, 1e-12, out);
    assert(fabs(out[0].root - out[1].root) < 1e-11);
    assert(fabs(cos(out[0].root) - out[0].root) < 1e-11);
    return 0;
}
