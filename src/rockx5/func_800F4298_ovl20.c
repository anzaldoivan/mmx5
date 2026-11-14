#include "types.h"
#include "addr.h"

extern s32 func_80017214(u8* a0, s32 a1, s32 a2);
extern s32 func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800F5944_ovl20[];
extern u16 D_800F595C_ovl20[][2];
extern u16 D_800F596C_ovl20[][2];
extern u8 D_800D1CCB;
extern s8 D_800D1C00[];

void func_800F4298_ovl20(u8* p) {
    u32* t;
    s32 st;
    s32* s;

    t = D_80098118;
    *(u16*)(p + 0x42) = 0x7800;
    st = *(s8*)(p + 2);
    *(u16*)(p + 0x40) = t[0] >> 7;
    s = D_1F800020.s32s;
    *(s32*)(p + 0x3C) = (s32)s + s[0];
    *(u8**)(p + 0x30) = D_800F5944_ovl20;
    if (st < 2) {
        p[0x16] = 3;
        *(u16*)(p + 0xA) = D_800F595C_ovl20[st][0];
        *(u16*)(p + 0xE) = D_800F595C_ovl20[st][1];
        if (st == 0) {
            if (D_800D1CCB & 1) {
                func_80017214(p, 0, 1);
            } else {
                func_80017214(p, 0, 0);
            }
        } else {
            if (D_800D1CCB & 1) {
                func_80017214(p, 1, 1);
            } else {
                func_80017214(p, 1, 0);
            }
        }
        p[4] = 1;
    } else if (st == 2) {
        *(u16*)(p + 0x42) = 0x78C0;
        p[0x16] = 2;
        *(u16*)(p + 0xA) = D_800F595C_ovl20[D_800D1C00[0x2C]][0];
        *(u16*)(p + 0xE) = D_800F595C_ovl20[D_800D1C00[0x2C]][1] + 5;
        func_800171E8(p, 2);
        p[4] = 2;
    } else if (st == 3) {
        p[0x16] = 3;
        *(u16*)(p + 0xA) = 0x3F0;
        *(u16*)(p + 0xE) = 0x51;
        func_800171E8(p, 3);
        p[4] = 3;
    } else if (st < 6) {
        p[0x16] = 3;
        *(u16*)(p + 0xA) = D_800F596C_ovl20[st - 4][0];
        *(u16*)(p + 0xE) = D_800F596C_ovl20[st - 4][1];
        func_80017214(p, 4, st - 4);
        p[4] = 4;
    } else if (st == 6) {
        *(u16*)(p + 0x42) = 0x78C0;
        p[0x16] = 2;
        *(u16*)(p + 0xA) = D_800F596C_ovl20[D_800D1C00[0x31]][0];
        *(u16*)(p + 0xE) = D_800F596C_ovl20[D_800D1C00[0x31]][1] + 5;
        func_800171E8(p, 5);
        p[4] = 5;
    } else if (st < 9) {
        p[0x16] = 3;
        *(u16*)(p + 0xA) = D_800F595C_ovl20[st - 5][0];
        *(u16*)(p + 0xE) = D_800F595C_ovl20[st - 5][1];
        if (st == 7) {
            if (D_800D1CCB & 1) {
                func_80017214(p, 0, 1);
            } else {
                func_80017214(p, 0, 0);
            }
        } else {
            if (D_800D1CCB & 1) {
                func_80017214(p, 1, 1);
            } else {
                func_80017214(p, 1, 0);
            }
        }
        p[4] = 1;
        p[2] -= 7;
    } else if (st == 9) {
        *(u16*)(p + 0x42) = 0x78C0;
        p[0x16] = 2;
        *(u16*)(p + 0xA) = D_800F595C_ovl20[D_800D1C00[0x2C]][0];
        *(u16*)(p + 0xE) = D_800F595C_ovl20[D_800D1C00[0x2C]][1] + 5;
        func_800171E8(p, 2);
        p[4] = 2;
    } else if (st == 10) {
        p[0x16] = 3;
        *(u16*)(p + 0xA) = 0x30;
        *(u16*)(p + 0xE) = 0x51;
        func_800171E8(p, 3);
        p[4] = 3;
    }
    p[0x14] = 1;
    p[0x15] = 0;
}
