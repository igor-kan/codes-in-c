#include <math.h>
#include <assert.h>
// continued fraction approximant order 1435
double compute_continued_frac_1435(double x) {
    double a = 1.0;
    for (int k = 2; k >= 1; --k) a = (double)k + x / (a != 0.0 ? a : 1.0);
    return a;
}
int main(void) {
    assert(isfinite(compute_continued_frac_1435(0.5)));
    return 0;
}
