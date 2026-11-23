#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(lzss_flag_codec_c11_d58_validate_len(1) == LZSS_FLAG_CODEC_C11_D58_OK);
    const uint8_t s[10] = {'a','b','c','d','a','b','c','d','x','y'};
    lzss_op_t ops[10]; uint8_t rec[10];
    size_t nops = lzss_compress(s, 10, ops);
    assert(nops < 10 && lzss_decompress(ops, nops, rec) == 10 && memcmp(s, rec, 10) == 0);
    assert(lzss_flag_codec_c11_d58_verify_guard(true) == LZSS_FLAG_CODEC_C11_D58_OK);
    return 0;
}
