#include "interface.h"

double fast_secant_step(double a, double b, double fa, double fb) {
    return b - fb * (b - a) / (fb - fa);
}
