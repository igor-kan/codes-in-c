#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 524
double compute_spherical_harm_524(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_524(0.5)));
    return 0;
}
