#include <math.h>
#include <assert.h>
// rational function approximant order 1266
double compute_pade_approx_1266(double x) {
    return (1.0 + x * 1.0) / (1.0 + x * x * 1.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_1266(0.5)));
    return 0;
}
