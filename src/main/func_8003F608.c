#include "types.h"

s32 func_8003F7A0(u8* a0);
extern s8 D_800749A0[];
extern u8 D_800D1D10;

void func_8003F608(u8* a0) {
    s8 i;

    if ((*(u16*)(a0 + 0x80) & 0x10) ||
        ((*(u16*)(a0 + 0x7C) & 0x10) && (D_800D1D10 & 2))) {
        if (*(s8*)(a0 + 0x93) != 0) {
            if (func_8003F7A0(a0) == 0) {
                return;
            }
            if (*(s8*)(a0 + 0x93) == 2) {
                return;
            }
        }
        a0[0x96] = a0[0x94];
        return;
    }
    if ((*(u32*)(a0 + 0x7C) & 0x100010) == 0x100000) {
        i = a0[0x94];
        if (i != 0 && D_800749A0[i] == 0) {
            if (*(s8*)(a0 + 0x93) == 0 || func_8003F7A0(a0) != 0) {
                a0[0x96] = a0[0x94];
            }
        }
    }
}
