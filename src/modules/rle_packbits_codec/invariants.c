#include "interface.h"
#include <stdlib.h>
#include <string.h>

rle_packbits_codec_err_t packbits_verify_roundtrip(const uint8_t* src, size_t len) {
    size_t cap = packbits_worst_case_size(len);
    uint8_t* enc = (uint8_t*)malloc(cap);
    uint8_t* dec = (uint8_t*)malloc(len + 1U);
    if (!enc || !dec) { free(enc); free(dec); return RLE_PACKBITS_CODEC_ERR_NULL; }
    size_t el = 0, dl = 0;
    rle_packbits_codec_err_t err = packbits_encode(src, len, enc, cap, &el);
    if (err == RLE_PACKBITS_CODEC_OK) err = packbits_decode(enc, el, dec, len + 1U, &dl);
    int match = (err == RLE_PACKBITS_CODEC_OK && dl == len && (len == 0 || memcmp(src, dec, len) == 0));
    free(enc);
    free(dec);
    return match ? RLE_PACKBITS_CODEC_OK : RLE_PACKBITS_CODEC_ERR_INVARIANT;
}
