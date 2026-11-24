#ifndef JENKINS_OAAT_C11_D59_TYPES_H
#define JENKINS_OAAT_C11_D59_TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t digest;
    size_t len;
} joat_out_t;

typedef struct {
    uint32_t version;
    uint32_t flags;
} jenkins_oaat_c11_d59_meta_t;

#endif /* JENKINS_OAAT_C11_D59_TYPES_H */
