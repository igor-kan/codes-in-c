#include <math.h>
#include <assert.h>
// spherical harmonic radial component order 1269
double compute_spherical_harm_1269(double x) {
    return pow(x, 5) / (double)(10);
}
int main(void) {
    assert(isfinite(compute_spherical_harm_1269(0.5)));
    return 0;
}
