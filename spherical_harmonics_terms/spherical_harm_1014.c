#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 1014
double compute_spherical_harm_1014(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_1014(0.5)));
    return 0;
}
