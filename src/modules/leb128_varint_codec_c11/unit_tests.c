#include "interface.h"
#include <assert.h>
#include <math.h>
#include <string.h>

int main(void) {
    assert(leb128_varint_codec_c11_validate_len(1) == LEB128_VARINT_CODEC_C11_OK);
    uint8_t buf[10];
    size_t n = uleb128_encode(624485ULL, buf);
    assert(n == 3 && buf[0] == 0xE5 && buf[1] == 0x8E && buf[2] == 0x26);
    uint64_t v = 0;
    size_t used = 0;
    assert(uleb128_decode(buf, 10, &v, &used) == 0 && v == 624485ULL && used == 3);
    assert(leb128_varint_codec_c11_verify_guard(true) == LEB128_VARINT_CODEC_C11_OK);
    return 0;
}
