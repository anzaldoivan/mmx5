#include "types.h"

extern u8 D_80075520[];
extern u8 D_8007BD08[];
extern u8 D_8009A0A0[];
extern u8 D_800D1C4A;
extern void func_800171E8(u8* obj, s32 state);

void func_80052E44(u8* o) {
    u8* g;

    o[0x5C] = 0xF;
    ((s8*)o)[0x60] = -8;
    *(u8**)(o + 0x58) = D_80075520;
    g = D_8009A0A0;
    o[0x61] = 0;
    o[0x14] = g[0x14];
    *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
    *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
    *(u8**)(o + 0x30) = D_8007BD08;
    o[0x16] = 3;
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x68) = 0;
    if (((s8*)g)[2] == 0) {
        if (*(s32*)(g + 0xFC) & 0x400) {
            o[0x85] = 1;
        } else {
            o[0x85] = 0;
        }
    } else if ((D_800D1C4A & 0x10) || (*(s32*)(g + 0xFC) & 0x400)) {
        o[0x85] = 1;
    } else {
        o[0x85] = 0;
    }
    func_800171E8(o, 4);
    o[0x67] = 1;
    *(s32*)(o + 0x80) = 0xE10;
    *(s32*)(o + 0x20) = 0;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x24) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[4] = 1;
    o[5] = 2;
    o[6] = 0;
}
