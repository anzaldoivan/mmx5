#include "types.h"

extern s8 D_800D1C00[];

void func_80057B28(u8* a0) {
    if ((D_800D1C00[0xC] == 12 && D_800D1C00[0x31] == 2 &&
         D_800D1C00[0x1D] == 0x15) ||
        D_800D1C00[0xC] == 0) {
        if (--*(u16*)(a0 + 0x14) == 0xFFFF) {
            D_800D1C00[0xF] = 0x40;
        }
    } else {
        if (--*(u16*)(a0 + 0x14) == 0xFFFF) {
            a0[4]++;
        }
    }
}
