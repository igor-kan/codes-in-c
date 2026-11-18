#include "interface.h"
#include <math.h>
#include <string.h>

void pchip_build(pchip_spline_t* s, const double* x, const double* y, size_t n) {
    s->n = n;
    double d[64] = {0.0};
    for (size_t i = 0; i < n; ++i) { s->x[i] = x[i]; s->y[i] = y[i]; }
    for (size_t i = 0; i + 1 < n; ++i) d[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
    s->m[0] = d[0]; s->m[n - 1] = d[n - 2];
    for (size_t i = 1; i + 1 < n; ++i) {
        s->m[i] = (d[i - 1] * d[i] <= 0.0) ? 0.0 : 0.5 * (d[i - 1] + d[i]);
    }
}
double pchip_eval(const pchip_spline_t* s, double xq) {
    size_t i = 0;
    while (i + 2 < s->n && xq > s->x[i + 1]) ++i;
    double h = s->x[i + 1] - s->x[i];
    double t = (xq - s->x[i]) / h, t2 = t * t, t3 = t2 * t;
    double h00 = 2 * t3 - 3 * t2 + 1, h10 = t3 - 2 * t2 + t;
    double h01 = -2 * t3 + 3 * t2,     h11 = t3 - t2;
    return h00 * s->y[i] + h10 * h * s->m[i] + h01 * s->y[i + 1] + h11 * h * s->m[i + 1];
}
