#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern u32* D_80098118;
extern u8 D_800F556C_ovl20[];
extern u16 D_800F5580_ovl20[];

void func_800F2AB4_ovl20(u8* obj) {
    s32 i;
    s32 s;
    u8 t;
    u32* g;

    g = D_80098118;
    i = ((s8*)obj)[2];
    *(s16*)(obj + 0x42) = 0x7800;
    *(s16*)(obj + 0x40) = g[0] >> 7;
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[0];
    *(u8**)(obj + 0x30) = D_800F556C_ovl20;
    *(s16*)(obj + 0xA) = D_800F5580_ovl20[i * 2];
    *(s16*)(obj + 0xE) = (&D_800F5580_ovl20[i * 2])[1];
    obj[0x16] = 3;
    if (i >= 7) {
        obj[2] -= 7;
    }
    t = obj[2];
    obj[0x14] = 1;
    obj[0x15] = 0;
    obj[4] = t + 1;
    if ((s8)t == 2) {
        func_800171E8(obj, 2);
    }
    s = ((s8*)obj)[2];
    if (s == 3) {
        obj[0x16] = 0;
        *(s16*)(obj + 0x42) = 0x78C0;
        func_800171E8(obj, 3);
    } else if (s >= 4) {
        obj[0x16] = 1;
        *(s16*)(obj + 0x42) = 0x78C0;
        func_80017214(obj, 4, s - 4);
    }
}
