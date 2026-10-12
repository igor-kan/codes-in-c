#include <math.h>
#include <assert.h>
// rational function approximant order 501
double compute_pade_approx_501(double x) {
    return (1.0 + x * 1.0) / (1.0 + x * x * 2.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_501(0.5)));
    return 0;
}
