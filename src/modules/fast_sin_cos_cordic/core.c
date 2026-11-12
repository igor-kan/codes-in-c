/**
 * @file core.c
 * @brief CORDIC shift-and-add trigonometric vector rotation for CORDIC Shift-and-Add Trigonometric Vector Rotation.
 * Module: fast_sin_cos_cordic
 */

#include "types.c"
#include <math.h>

static const double fast_sin_cos_cordic_angles[8] = {
    0.7853981633974483, 0.4636476090008061, 0.24497866312686414, 0.12435499454676144,
    0.06241880999595735, 0.031239833430268277, 0.015623728620476831, 0.007812341060101111
};

void fast_sin_cos_cordic_cordic_rotation(double theta, double* cos_out, double* sin_out) {
    double x = 0.60725293500888125617; // Initial scaling K
    double y = 0.0;
    double z = theta;
    for (int i = 0; i < 8; ++i) {
        double d = (z >= 0.0) ? 1.0 : -1.0;
        double next_x = x - d * y * ldexp(1.0, -i);
        double next_y = y + d * x * ldexp(1.0, -i);
        z -= d * fast_sin_cos_cordic_angles[i];
        x = next_x;
        y = next_y;
    }
    if (cos_out) *cos_out = x;
    if (sin_out) *sin_out = y;
}
