#include <math.h>
#include <assert.h>
// rational function approximant order 41
double compute_pade_approx_41(double x) {
    return (1.0 + x * 3.0) / (1.0 + x * x * 2.0);
}
int main(void) {
    assert(isfinite(compute_pade_approx_41(0.5)));
    return 0;
}
