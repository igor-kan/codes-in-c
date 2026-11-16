#include "interface.h"

rle_packbits_codec_err_t packbits_validate_caps(size_t src_len, size_t enc_cap) {
    if (enc_cap < packbits_worst_case_size(src_len)) return RLE_PACKBITS_CODEC_ERR_BOUNDS;
    return RLE_PACKBITS_CODEC_OK;
}
