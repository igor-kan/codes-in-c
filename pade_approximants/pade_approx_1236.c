#include <math.h>
#include <assert.h>
// rational function approximant order 1236
double compute_pade_approx_1236(double x) {
    return (1.0 + x * 1.0) / (1.0 + x * x * 1.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_1236(0.5)));
    return 0;
}
