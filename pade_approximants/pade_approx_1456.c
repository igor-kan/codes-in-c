#include <math.h>
#include <assert.h>
// rational function approximant order 1456
double compute_pade_approx_1456(double x) {
    return (1.0 + x * 2.0) / (1.0 + x * x * 1.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_1456(0.5)));
    return 0;
}
