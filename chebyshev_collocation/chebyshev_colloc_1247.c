#include <math.h>
#include <assert.h>
// chebyshev collocation node order 1247
double compute_chebyshev_colloc_1247(double x) {
    return cos(3.14159265358979 * 7.0 / 8.0) * x;
}
int main(void) {
    assert(isfinite(compute_chebyshev_colloc_1247(0.5)));
    return 0;
}
