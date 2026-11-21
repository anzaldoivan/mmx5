#include "types.h"

void func_800F0B94_ovl24(u8* arg0) {
    arg0[2]++;
}

void func_800F0BA8_ovl24(u8* a0) {
    u8 v = a0[0x194];
    u32 i;

    if (v == 0xFF) {
        a0[0] = 3;
    } else {
        a0[0] = 0x13;
        a0[0x1D] = v;
    }
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0;
    do {
        i = 0;
    } while (
        0); // !FAKE: fence keeps the index clear after the byte stores (C0294)
    a0 += 0x26;
    for (; i < 16; i++) {
        a0[i] = 0;
    }
}
