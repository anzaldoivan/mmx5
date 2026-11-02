#include "types.h"

extern void func_8002D6FC(u8* obj);
extern s32 func_800F6A7C_ovl06(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];

void func_800F6B60_ovl06(u8* obj) {
    u8* sys = D_800D1C00;
    u8* sys2;
    u8* g;
    u8* g2;
    u8* g3;
    u8* g4;
    u8* g5;
    u8* g6;
    u8 cnt;
    u8 t;

    if (*(s8*)(sys + 0x1D) > 0) {
        func_8002D6FC(obj);
        return;
    }
    cnt = obj[4];
    if (*(s8*)(obj + 4) == 0) {
        g = D_8009A0A0;
        obj[0x14] = 6;
        obj[0x15] = g[0xD5];
        obj[0x16] = g[0x67];
        obj[4] = cnt + 1;
    }
    g2 = D_8009A0A0;
    if (*(s8*)(obj + 0x15) != *(s8*)(g2 + 0xD5)) {
        if (*(s8*)(g2 + 0xD5) >= 0) {
            obj[0x14] = 0;
        }
    }
    g3 = D_8009A0A0;
    if (*(s8*)(obj + 0x16) != *(s8*)(g3 + 0x67) && *(s8*)(g3 + 0x67) == -1) {
        obj[0x14] = 0;
    }
    if (func_800F6A7C_ovl06(obj) != 0) {
        g5 = D_8009A0A0;
        t = g5[0x5C];
        *(s8*)(g5 + 0x5C) = -0x80;
        sys2 = D_800D1C00;
        *(s32*)(sys2 + 0xB8) += t & 0x7F;
    }
    {
        u8* dst = D_8009A1F8;
        s16 e;
        s16 x;
        g6 = D_8009A0A0;
        e = *(s16*)(g6 + 0xE);
        x = *(s16*)(g6 + 0xA);
        if (e < 0x201 && (u32)(x - 0x631) < 0x3DF) {
            if (x < 0x640) {
                *(s16*)(dst + 0x2A) = 0xF0;
            } else if (x < 0x781) {
                *(s16*)(dst + 0x2A) = (x - 0x640) / 5 + 0xF0;
            } else if (x < 0x8C0) {
                *(s16*)(dst + 0x2A) = 0x130;
            } else if (x < 0xA01) {
                *(s16*)(dst + 0x2A) = (0xA00 - x) / 4 + 0xE0;
            } else {
                *(s16*)(dst + 0x2A) = 0xE0;
            }
        }
    }
    g4 = D_8009A0A0;
    obj[0x15] = g4[0xD5];
    obj[0x16] = g4[0x67];
}
