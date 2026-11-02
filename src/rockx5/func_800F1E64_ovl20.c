#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D33C(u8* p, s32 backward);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern u32* D_80098118;
extern u8 D_800F53C4_ovl20[];
extern u8 D_800D1C00[];

void func_800F1E64_ovl20(u8* obj) {
    u8* p;
    u8* d;
    u8* e;
    u8* g;

    *(s16*)(obj + 0x40) = D_80098118[0] >> 7;
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[0];
    *(u8**)(obj + 0x30) = D_800F53C4_ovl20;
    *(s16*)(obj + 0xA) = 0xC0;
    *(s16*)(obj + 0xE) = 0x48;
    obj[0x16] = 3;
    obj[0x14] = 1;
    obj[0x15] = 0;
    d = D_800D1C00;
    if (((s8*)d)[0x2A] == 5) {
        if (!(d[0x4A] & 0x10)) {
            *(s16*)(obj + 0x42) = 0x7844;
        } else {
            *(s16*)(obj + 0x42) = 0x7884;
        }
    } else {
        *(s16*)(obj + 0x42) = 0x7840;
    }
    if (((s8*)obj)[2] == 0) {
        e = D_800D1C00;
        if (((s8*)e)[0x2A] == 5) {
            func_800171E8(obj, 1);
        } else {
            func_800171E8(obj, 0);
        }
        obj[4] = 1;
        p = func_8002D33C(obj, 0);
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 10;
            p[2] = 1;
            *(u8**)(p + 0x50) = obj;
        }
    } else {
        g = D_800D1C00;
        obj[0x16] = 2;
        func_80017214(obj, 2, ((s8*)g)[0x2A]);
        obj[4] = 2;
    }
    obj[3] = 0;
}
