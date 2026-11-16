#include "interface.h"
#include <stdlib.h>
#include <string.h>

cobs_framing_codec_err_t cobs_verify_invariants(const uint8_t* payload, size_t len) {
    size_t cap = cobs_max_encoded_size(len);
    uint8_t* enc = (uint8_t*)malloc(cap);
    uint8_t* dec = (uint8_t*)malloc(len + 1U);
    if (!enc || !dec) { free(enc); free(dec); return COBS_FRAMING_CODEC_ERR_NULL; }
    size_t elen = 0, dlen = 0;
    if (cobs_encode(payload, len, enc, cap, &elen) != COBS_FRAMING_CODEC_OK) {
        free(enc); free(dec); return COBS_FRAMING_CODEC_ERR_INVARIANT;
    }
    for (size_t i = 0; i < elen; ++i) {
        if (enc[i] == 0) { free(enc); free(dec); return COBS_FRAMING_CODEC_ERR_INVARIANT; }
    }
    if (cobs_decode(enc, elen, dec, len + 1U, &dlen) != COBS_FRAMING_CODEC_OK ||
        dlen != len || (len > 0 && memcmp(payload, dec, len) != 0)) {
        free(enc); free(dec); return COBS_FRAMING_CODEC_ERR_INVARIANT;
    }
    free(enc); free(dec);
    return COBS_FRAMING_CODEC_OK;
}
