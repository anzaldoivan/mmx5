#include "types.h"

extern s32 func_8002DF78();
extern s8 D_800D1C00[];

void func_800FA004_ovl44(u8* obj) {
    s32 sum;
    s32 i;
    s32 amt;
    s32 hit;
    u32 r;
    u8 pad[8]; // !FAKE: keeps the 0x28 frame

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += D_800D1C00[0xC2 + i];
    }
    sum *= 4;
    sum >>= 1;
    sum += D_800D1C00[0xCA];
    if (sum >= 0x51) {
        amt = 0xD2F00;
    } else if (sum >= 0x3D) {
        amt = 0x9E340;
    } else if (sum >= 0x29) {
        amt = 0x69780;
    } else if (sum >= 0x15) {
        amt = 0x34BC0;
    } else if (sum > 0) {
        amt = 0x34BC0;
    } else {
        amt = 0;
    }
    obj[0xCB] = 1;
    *(s32*)(obj + 0xAC) += amt;
    D_800D1C00[0xCA] = 0;
    r = (func_8002DF78() >> 2) & 0xF;
    hit = 0;
    if (sum >= 0x51) {
        hit = r < 0xF;
    } else if (sum >= 0x3D) {
        if (r < 0xC) {
            hit = 1;
        }
    } else if (sum >= 0x29) {
        if (r < 6) {
            hit = 1;
        }
    } else if (sum >= 0x15) {
        if (r < 2) {
            hit = 1;
        }
    } else if (sum > 0 && r == 0) {
        hit = 1;
    }
    if (hit) {
        obj[0x79] = 5;
        obj[0xCB] |= 0x80;
    }
}
