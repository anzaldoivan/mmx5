#include "types.h"

extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];
extern u8 D_800D1C00[];

void func_800F01E8_ovl07(u8* obj) {
    s16 d;
    s16 x;
    u8 flags;
    u8 t;
    u8* e;
    u8* g;
    u8* h;

    e = D_8009A1F8;
    d = *(u16*)(obj + 0xA) - *(u16*)(e + *(s8*)(obj + 0x14) * 0x54 + 0xA);
    flags = obj[0x70] | obj[0x71];
    if (obj[0x15] == 0) {
        d = d + *(s8*)(*(u8**)(obj + 0x68));
    } else {
        d = d - *(s8*)(*(u8**)(obj + 0x68));
    }
    x = d - (*(u8**)(obj + 0x68))[2];
    if (x <= 0 && !(flags & 1)) {
        *(u16*)(obj + 0xA) = *(u16*)(obj + 0xA) + (x < 0 ? -x : x);
    } else if (x < -8) {
        g = D_8009A0A0;
        h = D_800D1C00;
        t = g[0x5C];
        *(s8*)(g + 0x5C) = -0x80;
        *(s32*)(h + 0xB8) = *(s32*)(h + 0xB8) + (t & 0x7F);
        *(s8*)(obj + 0x5C) = -0x80;
    }
    x = (*(u8**)(obj + 0x68))[2] + d;
    if (x >= 0x100) {
        x = x - 0x100;
        *(u16*)(obj + 0xA) = *(u16*)(obj + 0xA) - (x < 0 ? -x : x);
    }
}
