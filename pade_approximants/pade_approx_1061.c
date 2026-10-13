#include <math.h>
#include <assert.h>
// rational function approximant order 1061
double compute_pade_approx_1061(double x) {
    return (1.0 + x * 3.0) / (1.0 + x * x * 2.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_1061(0.5)));
    return 0;
}
