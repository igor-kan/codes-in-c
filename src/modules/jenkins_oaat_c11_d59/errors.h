#ifndef JENKINS_OAAT_C11_D59_ERRORS_H
#define JENKINS_OAAT_C11_D59_ERRORS_H

typedef enum jenkins_oaat_c11_d59_err {
    JENKINS_OAAT_C11_D59_OK = 0,
    JENKINS_OAAT_C11_D59_ERR_NULL = -1,
    JENKINS_OAAT_C11_D59_ERR_BOUNDS = -2,
    JENKINS_OAAT_C11_D59_ERR_INVALID = -3,
    JENKINS_OAAT_C11_D59_ERR_OVERFLOW = -4,
    JENKINS_OAAT_C11_D59_ERR_INVARIANT = -5
} jenkins_oaat_c11_d59_err_t;



static inline const char* jenkins_oaat_c11_d59_err_str(jenkins_oaat_c11_d59_err_t err) {
    switch (err) {
        case JENKINS_OAAT_C11_D59_OK: return "ok";
        case JENKINS_OAAT_C11_D59_ERR_NULL: return "null pointer supplied";
        case JENKINS_OAAT_C11_D59_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case JENKINS_OAAT_C11_D59_ERR_INVALID: return "domain precondition violated";
        case JENKINS_OAAT_C11_D59_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case JENKINS_OAAT_C11_D59_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* JENKINS_OAAT_C11_D59_ERRORS_H */
