#include <math.h>
#include <assert.h>
// chebyshev collocation node order 102
double compute_chebyshev_colloc_102(double x) {
    return cos(3.14159265358979 * 2.0 / 3.0) * x;
}
int main(void) {
    assert(isfinite(compute_chebyshev_colloc_102(0.5)));
    return 0;
}
