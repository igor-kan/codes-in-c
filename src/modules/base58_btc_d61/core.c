#include "interface.h"
#include <math.h>
#include <string.h>

static const char b58_alpha[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

static int b58_value(char ch) {
    for (int i = 0; i < 58; ++i) {
        if (b58_alpha[i] == ch) return i;
    }
    return -1;
}

size_t base58_encode(const uint8_t* data, size_t n, base58_string_t* out) {
    out->length = 0;
    if (data == NULL || n == 0 || n > (size_t)BASE58_MAX_IN) return 0;
    uint8_t digits[128];
    size_t nd = 0, zeros = 0;
    while (zeros < n && data[zeros] == 0) ++zeros;
    for (size_t i = zeros; i < n; ++i) {
        int carry = (int)data[i];
        for (size_t j = 0; j < nd; ++j) {
            int v = (int)digits[j] * 256 + carry;
            digits[j] = (uint8_t)(v % 58);
            carry = v / 58;
        }
        while (carry > 0) {
            digits[nd++] = (uint8_t)(carry % 58);
            carry /= 58;
        }
    }
    size_t pos = 0;
    for (size_t z = 0; z < zeros && pos + 1U < (size_t)BASE58_MAX_OUT; ++z) {
        out->text[pos++] = '1';
    }
    for (size_t j = nd; j > 0 && pos + 1U < (size_t)BASE58_MAX_OUT;) {
        --j;
        out->text[pos++] = b58_alpha[digits[j]];
    }
    out->text[pos] = '\0';
    out->length = pos;
    return pos;
}

size_t base58_decode(const char* text, size_t n, uint8_t* out, size_t cap) {
    if (text == NULL || out == NULL) return 0;
    uint8_t bytes[128];
    size_t nb = 0, zeros = 0;
    while (zeros < n && text[zeros] == '1') ++zeros;
    for (size_t i = zeros; i < n; ++i) {
        int val = b58_value(text[i]);
        if (val < 0) return 0;
        int carry = val;
        for (size_t j = 0; j < nb; ++j) {
            int v = (int)bytes[j] * 58 + carry;
            bytes[j] = (uint8_t)(v & 0xff);
            carry = v >> 8;
        }
        while (carry > 0) {
            bytes[nb++] = (uint8_t)(carry & 0xff);
            carry >>= 8;
        }
    }
    size_t total = zeros + nb;
    if (total > cap) return 0;
    size_t pos = 0;
    for (size_t z = 0; z < zeros; ++z) out[pos++] = 0;
    for (size_t j = nb; j > 0;) {
        --j;
        out[pos++] = bytes[j];
    }
    return pos;
}
