#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern u16 D_800C931C[];
extern u8 D_800D1C00[];
extern u8 D_800F6DF0_ovl20[];
extern u8 D_800F6DFB_ovl20;

void func_800EFF4C_ovl20(u8* arg0) {
    s8 old;
    QByte
        v; // !FAKE: one-byte struct keeps the QImode value and its andi 0xFF (C0279)

    old = D_800D1C00[0x30];
    if (D_800C931C[2] & 0x8000) {
        D_800D1C00[0x30]--;
        if ((s8)D_800D1C00[0x30] < 0) {
            D_800D1C00[0x30] = D_800F6DFB_ovl20 - 1;
        }
    } else if (D_800C931C[2] & 0x2000) {
        D_800D1C00[0x30]++;
        if ((s8)D_800D1C00[0x30] >= D_800F6DFB_ovl20) {
            D_800D1C00[0x30] = 0;
        }
    }
    if (old != (s8)D_800D1C00[0x30]) {
        func_80016490(5, 0, 0);
    }
    v.b = D_800F6DF0_ovl20[(s8)D_800D1C00[0x30]];
    D_800D1C00[0x2A] = v.b;
    if (D_800C931C[2] & 0x840) {
        arg0[0x49] = v.b;
        if (v.b == 5) {
            arg0[0x44] = 1;
        } else {
            arg0[0x44] = 0;
        }
        func_80016490(5, 1, 0);
        *(s16*)(arg0 + 8) = 0;
        arg0[2]++;
        return;
    }
    if (D_800C931C[2] & 0x10) {
        arg0[2] = 8;
        *(s16*)(arg0 + 8) = 0;
    }
}
