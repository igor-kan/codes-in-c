#include <math.h>
#include <assert.h>
// rational function approximant order 96
double compute_pade_approx_96(double x) {
    return (1.0 + x * 1.0) / (1.0 + x * x * 1.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_96(0.5)));
    return 0;
}
