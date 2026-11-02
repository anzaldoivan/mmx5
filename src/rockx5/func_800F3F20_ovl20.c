#include "types.h"
#include "addr.h"

extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern s8 D_800D1C00[];
extern s8 D_800D1C2A;
extern u8 D_800F58CC_ovl20[];

void func_800F3F20_ovl20(u8* o) {
    u8* p;
    u8* q;
    u8 r;

    ((u8**)o)[0xC] = D_800F58CC_ovl20;
    if (((s8*)o)[2] == 0) {
        ((s16*)o)[0x21] = 0x7800;
        ((s16*)o)[0x20] = D_80098118[0] >> 7;
        p = (u8*)D_1F800020.s32s;
        p += ((s32*)p)[0];
        ((u16*)o)[5] = 0x2F0;
        ((u16*)o)[7] = 0xD0;
        ((u8**)o)[0xF] = p;
        func_80017214(o, 6, D_800D1C2A);
        r = 2;
    } else {
        if (D_800D1C00[0x2A] == 5) {
            ((s16*)o)[0x21] = 0x7808;
            ((s16*)o)[0x20] = D_80098118[2] >> 7;
            q = (u8*)D_1F800020.s32s;
            q += ((s32*)q)[2];
            ((u8**)o)[0xF] = q;
        } else {
            ((s16*)o)[0x21] = 0x7804;
            ((s16*)o)[0x20] = D_80098118[1] >> 7;
            q = (u8*)D_1F800020.s32s;
            q += ((s32*)q)[1];
            ((u8**)o)[0xF] = q;
        }
        ((u16*)o)[5] = 0x300;
        ((u16*)o)[7] = 0xA8;
        if (D_800D1C00[0x2A] == 5 && (D_800D1C00[0x4A] & 0x10)) {
            func_800171E8(o, 7);
        } else {
            func_800171E8(o, D_800D1C00[0x2A]);
        }
        r = 1;
    }
    o[4] = r;
    o[0x16] = 3;
    o[0x14] = 1;
    o[0x15] = 0;
}
