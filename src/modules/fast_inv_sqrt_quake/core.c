/**
 * @file core.c
 * @brief Fast inverse square root with bitwise IEEE-754 mantissa hack for Fast Inverse Square Root with Bitwise IEEE-754 Hack.
 * Module: fast_inv_sqrt_quake
 */

#include "types.c"
#include <stdint.h>

float fast_inv_sqrt_quake_inv_sqrt(float number) {
    union {
        float f;
        uint32_t i;
    } conv;

    float x2 = number * 0.5f;
    conv.f = number;
    conv.i = 0x5f3759df - (conv.i >> 1); // Fast bitwise hack
    conv.f = conv.f * (1.5f - (x2 * conv.f * conv.f)); // 1st Newton-Raphson iteration
    return conv.f;
}
