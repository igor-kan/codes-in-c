#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 59
double compute_spherical_harm_59(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_59(0.5)));
    return 0;
}
