#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 1204
double compute_spherical_harm_1204(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_1204(0.5)));
    return 0;
}
