#include "types.h"

extern s32 func_8002DF78();
extern D_800D1C00_t D_800D1C00;

void func_800FA004_ovl48(u8* obj) {
    s32 sum;
    s32 i;
    s32 hit;
    u32 r;
    u8 id;

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += D_800D1C00.c6[i];
    }
    sum *= 4;
    sum += D_800D1C00.ca;
    id = obj[0xA9];
    if (id == 0xD) {
        sum = 0;
    }
    obj[0xCB] = 0x10;
    obj[0x79] = 5;
    r = (func_8002DF78(id) >> 2) & 0xF;
    hit = 0;
    if (sum >= 0x51) {
        hit = 1;
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
        obj[0xCB] |= 0x80;
    }
}
