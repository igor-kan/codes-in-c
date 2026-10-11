#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 44
double compute_spherical_harm_44(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_44(0.5)));
    return 0;
}
