#ifndef GOERTZEL_TONE_DETECTOR_D61_TYPES_H
#define GOERTZEL_TONE_DETECTOR_D61_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define GOERTZEL_MAX_BINS 64
typedef struct {
    double real;
    double imag;
} goertzel_complex_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} goertzel_tone_detector_d61_meta_t;

#endif /* GOERTZEL_TONE_DETECTOR_D61_TYPES_H */
