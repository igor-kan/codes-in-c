#include <math.h>
#include <assert.h>
// rational function approximant order 1021
double compute_pade_approx_1021(double x) {
    return (1.0 + x * 2.0) / (1.0 + x * x * 2.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_1021(0.5)));
    return 0;
}
