/**
 * @file core.c
 * @brief Numerically stable mean and variance calculation for Empirical Shannon Entropy Calculator with Log2 Scale.
 * Module: shannon_entropy_calc
 */

#include "types.c"

typedef struct shannon_entropy_calc_stat_acc {
    size_t count;
    double mean;
    double m2;
} shannon_entropy_calc_stat_acc_t;

void shannon_entropy_calc_add_sample(shannon_entropy_calc_stat_acc_t* s, double val) {
    if (!s) return;
    s->count += 1;
    double delta = val - s->mean;
    s->mean += delta / (double)s->count;
    double delta2 = val - s->mean;
    s->m2 += delta * delta2;
}

double shannon_entropy_calc_compute_var(const shannon_entropy_calc_stat_acc_t* s) {
    return (s && s->count > 1) ? (s->m2 / (double)(s->count - 1)) : 0.0;
}
