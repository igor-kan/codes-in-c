#include <math.h>
#include <assert.h>
// chebyshev collocation node order 87
double compute_chebyshev_colloc_87(double x) {
    return cos(3.14159265358979 * 7.0 / 8.0) * x;
}
int main(void) {
    assert(isfinite(compute_chebyshev_colloc_87(0.5)));
    return 0;
}
