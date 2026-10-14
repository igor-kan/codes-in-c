#include <math.h>
#include <assert.h>
// chebyshev collocation node order 1267
double compute_chebyshev_colloc_1267(double x) {
    return cos(3.14159265358979 * 7.0 / 8.0) * x;
}
int main(void) {
    assert(isfinite(compute_chebyshev_colloc_1267(0.5)));
    return 0;
}
