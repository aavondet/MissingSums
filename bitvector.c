#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "bitvector.h"

uint64_t POW (uint64_t x, uint64_t y)
{
    uint64_t b = x;
    uint64_t e = y;
    uint64_t r = 1;
    while (e > 0)
    {
        if (e % 2 == 1) {
            r = b * r;
        }
        b = b * b;
        e = e / 2;
    }
    return r;
}



bitvector bitvector_new() {
    bitvector new = 0;
    return new;
}

bool bitvector_get(bitvector B, uint8_t i) {
    return !(((B >> i) & 1) == 0);
}

bitvector bitvector_flip(bitvector B, uint8_t i) {
    bool one = bitvector_get(B, i);
    if (one) return B - POW(2, i);
    else return B + POW(2, i);
}

bool bitvector_equal(bitvector B1, bitvector B2){
    for (uint8_t i = 0; i < BITVECTOR_LIMIT; i++) {
        if (bitvector_get(B1, i) != bitvector_get(B2, i)) {
            return false;
        }
    }
    return true;
}
