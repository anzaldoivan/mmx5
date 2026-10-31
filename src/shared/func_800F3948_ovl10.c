/* Shared body (DK-5), from the banked draft of func_800F3948_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8* func_8002CA10(u8* obj, s32 arg1);
extern void func_800171E8(u8* obj, s32 state, s32 a2, s32 a3);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* obj) {
    s16 n;
    s32 d;
    s32 v;
    s32 gx;
    u8* p; // !FAKE: p also holds the s32 speed below; one variable gives the target's a1/t0 allocation
    u8* g;
    u8* g2;

    if (*(s16*)(obj + 0x7E) != 0) {
        n = --*(s16*)(obj + 0x7E);
        if (n == 1) {
            p = func_8002CA10(obj, 0);
            if (p != 0) {
                p[0] = 0x41;
                p[1] = obj[1];
                p[2] = n;
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
                *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
                p[0x15] = obj[0x15];
                *(u8**)(p + 0x80) = obj;
            }
        }
    } else {
        g = D_8009A0A0;
        gx = *(s32*)(g + 8);
        d = gx - *(s32*)(obj + 8);
        if (d >= 0) {
            p = (u8*)((d + 0x10000) / 60);
        } else {
            p = (u8*)((*(s32*)(obj + 8) - gx + 0x10000) / 60);
        }
        *(s32*)(obj + 0x20) = (s32)p;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0x64000;
        *(s32*)(obj + 0x2C) = 0x3800;
        g2 = D_8009A0A0;
        if (*(s16*)(g2 + 0xA) < *(s16*)(obj + 0xA)) {
            obj[0x15] = 0;
            *(s32*)(obj + 0x20) = -(s32)p;
        } else {
            obj[0x15] = 0x40;
        }
        func_800171E8(obj, 2, d, gx);
        obj[6] = 2;
    }
}
