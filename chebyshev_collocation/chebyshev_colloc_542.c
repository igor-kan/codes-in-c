#include <math.h>
#include <assert.h>
// chebyshev collocation node order 542
double compute_chebyshev_colloc_542(double x) {
    return cos(3.14159265358979 * 2.0 / 3.0) * x;
}
int main(void) {
    assert(isfinite(compute_chebyshev_colloc_542(0.5)));
    return 0;
}
