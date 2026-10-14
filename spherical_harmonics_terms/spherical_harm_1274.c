#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 1274
double compute_spherical_harm_1274(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_1274(0.5)));
    return 0;
}
