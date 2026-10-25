#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];

void func_800F07B4_ovl07(u8* obj) {
    s32 v;

    if (obj[0x82] == obj[0x83]) {
        return;
    }
    if (obj[0x80] & 2) {
        return;
    }
    switch (obj[0x82]) {
    case 0:
        func_800171E8(obj, 2);
        v = 0x45;
        break;
    case 1:
        func_800171E8(obj, 1);
        v = 0x43;
        break;
    case 2:
        func_800171E8(obj, 0);
        v = 0x41;
        break;
    default:
        return;
    }
    D_8009A0A0[0xD8] = v;
    D_8009A0A0[6] = 0;
}
