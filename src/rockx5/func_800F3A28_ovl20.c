#include "types.h"
#include "addr.h"

extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D6FC(u8* obj);
extern u32* D_80098118;
extern s8 D_800D1C00[];
extern s8 D_800D1C32;
extern u16 D_800F5724_ovl20[][2];
extern u8 D_800F5814_ovl20[];

void func_800F3A28_ovl20(u8* o) {
    s8 s;
    s32* p;
    s8* g;
    s8* h;

    ((s16*)o)[0x21] = 0x7800;
    s = ((s8*)o)[2];
    ((s16*)o)[0x20] = *D_80098118 >> 7;
    p = D_1F800020.s32s;
    ((u8**)o)[0xF] = (u8*)p + *p;
    ((u8**)o)[0xC] = D_800F5814_ovl20;
    if (s < 0x10) {
        func_80017214(o, 0, s);
        ((u16*)o)[5] = D_800F5724_ovl20[((s8*)o)[2]][0];
        ((u16*)o)[7] = D_800F5724_ovl20[((s8*)o)[2]][1];
        o[0x16] = 3;
        o[4] = 1;
    } else if (s == 0x10) {
        func_800171E8(o, 2);
        ((s16*)o)[0x21] = 0x7888;
        ((u16*)o)[5] = 0x200;
        ((u16*)o)[7] = 0x78;
        o[0x16] = 4;
        o[4] = 1;
    } else if (s < 0x21) {
        func_800171E8(o, 3);
        ((u16*)o)[5] = D_800F5724_ovl20[((s8*)o)[2] - 0x11][0];
        ((u16*)o)[7] = D_800F5724_ovl20[((s8*)o)[2] - 0x11][1];
        o[0x16] = 2;
        o[2] = o[2] - 0x11;
        o[4] = 2;
    } else if (s == 0x21) {
        g = D_800D1C00;
        if (g[0x32] == -1) {
            func_8002D6FC(o);
            return;
        }
        func_800171E8(o, 4);
        ((u16*)o)[5] = D_800F5724_ovl20[g[0x32]][0];
        ((u16*)o)[7] = D_800F5724_ovl20[g[0x32]][1];
        o[0x16] = 1;
        o[4] = 3;
    } else if (s == 0x22) {
        s = D_800D1C32;
        if (s == -1) {
            func_8002D6FC(o);
            return;
        }
        func_80017214(o, 1, s);
        ((u16*)o)[5] = 0x1F4;
        ((u16*)o)[7] = 0x7F;
        o[0x16] = 3;
        o[4] = 4;
    } else if (s == 0x23) {
        h = D_800D1C00;
        if (h[0x30] == 4) {
            func_80017214(o, 5, h[0x31]);
        } else if (h[0x30] == 2) {
            func_80017214(o, 5, h[0x31] + 5);
        } else {
            func_80017214(o, 5, 8);
        }
        ((s16*)o)[0x21] = 0x78C0;
        ((u16*)o)[5] = 0x1D0;
        ((u16*)o)[7] = 0x60;
        o[0x16] = 1;
        o[4] = 5;
    }
    o[0x14] = 1;
    o[0x15] = 0;
}
