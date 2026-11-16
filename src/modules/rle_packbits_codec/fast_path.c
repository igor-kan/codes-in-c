#include "interface.h"

rle_packbits_codec_err_t packbits_encode_fast(const uint8_t* src, size_t len, uint8_t* dst, size_t dst_cap, size_t* out_len) {
    return packbits_encode(src, len, dst, dst_cap, out_len);
}
