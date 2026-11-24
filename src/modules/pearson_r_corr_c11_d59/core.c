#include "interface.h"
#include <math.h>
#include <string.h>

void welford_init(welford_t *w) {
    w->count = 0;
    w->mean = 0.0;
    w->m2 = 0.0;
}

void welford_add(welford_t *w, double x) {
    w->count++;
    double delta = x - w->mean;
    w->mean += delta / (double)w->count;
    double delta2 = x - w->mean;
    w->m2 += delta * delta2;
}

double welford_var(const welford_t *w) {
    return w->count < 2 ? 0.0 : w->m2 / (double)(w->count - 1);
}
