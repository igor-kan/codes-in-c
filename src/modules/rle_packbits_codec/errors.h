#ifndef RLE_PACKBITS_CODEC_ERRORS_H
#define RLE_PACKBITS_CODEC_ERRORS_H

typedef enum rle_packbits_codec_err {
    RLE_PACKBITS_CODEC_OK = 0,
    RLE_PACKBITS_CODEC_ERR_NULL = -1,
    RLE_PACKBITS_CODEC_ERR_BOUNDS = -2,
    RLE_PACKBITS_CODEC_ERR_INVALID = -3,
    RLE_PACKBITS_CODEC_ERR_OVERFLOW = -4,
    RLE_PACKBITS_CODEC_ERR_INVARIANT = -5
} rle_packbits_codec_err_t;



static inline const char* rle_packbits_codec_err_str(rle_packbits_codec_err_t err) {
    switch (err) {
        case RLE_PACKBITS_CODEC_OK: return "ok";
        case RLE_PACKBITS_CODEC_ERR_NULL: return "null pointer supplied";
        case RLE_PACKBITS_CODEC_ERR_BOUNDS: return "dimension or capacity out of bounds";
        case RLE_PACKBITS_CODEC_ERR_INVALID: return "domain precondition violated";
        case RLE_PACKBITS_CODEC_ERR_OVERFLOW: return "arithmetic overflow or non-finite value";
        case RLE_PACKBITS_CODEC_ERR_INVARIANT: return "postcondition invariant violated";
        default: return "unknown error";
    }
}

#endif /* RLE_PACKBITS_CODEC_ERRORS_H */
