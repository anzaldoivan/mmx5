#include "types.h"

void func_8003F4C4(u8* p, s32 idx) {
    s8 c;
    u8 m;

    if (!(*(s32*)(p + 0xFC) & 0x1000)) {
        c = ((Obj8003F4C4*)p)->x9B[idx];
        if (c == 0) {
            return;
        }
        if (c == 1) {
            ((Obj8003F4C4*)p)->x94[idx] = 9;
            return;
        }
    }
    m = p[0xFA];
    if (m == 1 || m == 4) {
        (p + idx)[0x94] = 0x14;
    } else if (m == 2) {
        (p + idx)[0x94] = 0x13;
    } else {
        (p + idx)[0x94] = 0x12;
    }
}
