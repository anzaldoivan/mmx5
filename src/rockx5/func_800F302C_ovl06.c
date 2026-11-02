#include "types.h"

extern void func_8002E058(void*, s32);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FE470_ovl06[];
extern s16 D_800FE474_ovl06[];

void func_800F302C_ovl06(u8* o) {
    s32 idx;
    u8 flip;
    s16 dx;
    s32 anim;
    s32 k;
    s32 x;
    s32 y;

    o[4] = 1;
    o[3] = 1;
    idx = ((s8*)o)[2];
    flip = o[0x15];
    o[0x16] = 0;
    *(s32*)(o + 0x68) = 0;
    *(s32*)(o + 0x54) = 0;
    *(u8**)(o + 0x50) = D_800FE470_ovl06;
    k = idx * 2;
    dx = D_800FE474_ovl06[k];
    if (flip != 0) {
        dx = -dx;
    }
    *(s16*)(o + 0xA) += dx;
    *(s16*)(o + 0xE) += D_800FE474_ovl06[k + 1];
    switch (idx) {
    case 0:
        anim = (flip == 0) << 4;
        break;
    case 1:
        anim = 0x1C;
        if (flip == 0) {
            anim = 0x14;
        }
        break;
    case 2:
        anim = 4;
        if (flip == 0) {
            anim = 0xC;
        }
        break;
    }
    o[0x90] = anim;
    func_8002E058(o, anim);
    x = *(s32*)(o + 0x20);
    y = *(s32*)(o + 0x24);
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x5C] = 1;
    o[0x60] = 3;
    *(s16*)(o + 0x88) = 8;
    *(s16*)(o + 0x8A) = 1;
    *(s32*)(o + 0x8C) = 0;
    *(s32*)(o + 0x84) = 0;
    *(s32*)(o + 0x20) = x * 6;
    *(s32*)(o + 0x24) = y * 6;
    func_800171E8(o, 0x21);
}
