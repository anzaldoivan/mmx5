#include "types.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0A0[];

void func_800F8864_ovl28(u8* o) {
    u8* p;
    u8* g;
    u16 a;
    u16 e;
    s16 ang;

    p = *(u8**)(o + 0x7C);
    *(u16*)(o + 0x40) = *(u16*)(p + 0x40);
    *(u16*)(o + 0x42) = 0x7CCC;
    *(s32*)(o + 0x30) = *(s32*)(p + 0x30);
    *(s32*)(o + 0x3C) = *(s32*)(p + 0x3C);
    o[0x14] = 0;
    o[0x16] = 1;
    o[0x15] = p[0x15];
    o[0x67] = 0;
    o[0x3] = 0;
    *(s32*)(o + 0x68) = 0;
    *(s32*)(o + 0x50) = 0;
    *(s32*)(o + 0x54) = 0;
    *(s32*)(o + 0x58) = 0;
    a = *(u16*)(p + 0xA);
    *(u16*)(o + 0xA) = a;
    e = *(u16*)(p + 0xE);
    *(u16*)(o + 0xE) = e;
    g = D_8009A0A0;
    ang = ratan2(*(s16*)(g + 0xE) - (s16)e, *(s16*)(g + 0xA) - (s16)a);
    *(s32*)(o + 0x20) = rcos(ang) << 7;
    *(s32*)(o + 0x24) = -rsin(ang) << 7;
    *(s32*)(o + 0x28) = 0;
    *(s32*)(o + 0x2C) = 0;
    o[0x5C] = 0;
    o[0x60] = 0;
    func_800171E8(o, 0x12);
    o[0x5] = 0;
    o[0x4]++;
}
