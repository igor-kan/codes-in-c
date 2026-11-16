#ifndef KFIFO_POWER2_RING_TYPES_H
#define KFIFO_POWER2_RING_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t* data;
    uint32_t mask;
    uint32_t in;
    uint32_t out;
} kfifo_t;

#endif /* KFIFO_POWER2_RING_TYPES_H */
