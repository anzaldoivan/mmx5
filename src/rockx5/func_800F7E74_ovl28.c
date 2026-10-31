#include "types.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FE74C_ovl28[];
extern u8 D_800FE754_ovl28[];
extern u8 D_800FE758_ovl28[];
extern u8 D_80074E40[];
extern u8 D_8009A0A0[];

void func_800F7E74_ovl28(u8* o) {
    u8* p;
    u8* g;
    s32 e;
    s32 x;
    s32 ang;

    p = *(u8**)(o + 0x7C);
    *(u16*)(o + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(o + 0x42) = *(u16*)(p + 0x42) & 0x7FFF;
    *(s32*)(o + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(o + 0x3C) = *(s32*)(p + 0x3C);
    o[0x14] = 0;
    o[0x16] = 1;
    o[0x15] = p[0x15];
    o[0x67] = 0;
    o[0x3] = 0;
    *(u8**)(o + 0x68) = D_800FE74C_ovl28;
    *(u8**)(o + 0x50) = D_800FE754_ovl28;
    *(u8**)(o + 0x54) = D_800FE758_ovl28;
    *(u8**)(o + 0x58) = D_80074E40;
    if (o[0x15] == 0) {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) - 0x1E;
    } else {
        *(u16*)(o + 0xA) = *(u16*)(p + 0xA) + 0x1E;
    }
    x = *(s16*)(o + 0xA);
    e = *(u16*)(*(u8**)(o + 0x7C) + 0xE) - 0xA;
    g = D_8009A0A0;
    *(u16*)(o + 0xE) = e;
    ang = (*(s16*)(g + 0xA) >= x) << 6;
    if (o[0x15] == ang) {
        x = *(s16*)(g + 0xA) - x;
    } else {
        x = x - *(s16*)(g + 0xA);
    }
    ang = (s16)ratan2(*(s16*)(g + 0xE) - (s16)e, x);
    if (ang <= 0) {
        if (ang >= -0x3FF) {
            if (ang < -0x200) {
                ang = -0x200;
            }
        } else if (ang >= -0x5FF) {
            ang = -0x600;
        }
    } else if (ang < 0x400) {
        ang = 0;
    } else {
        ang = -0x800;
    }
    *(s32*)(o + 0x20) = rcos(ang) << 6;
    *(s32*)(o + 0x24) = -rsin(ang) << 6;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x5C] = 1;
    o[0x60] = 8;
    func_800171E8(o, 0xE);
    *(s32*)(o + 0x8C) = 0;
    o[0x5] = 0;
    o[0x4]++;
}
