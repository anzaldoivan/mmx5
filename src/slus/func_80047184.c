#include "types.h"

extern u32* D_800730AC[];
extern u8 D_800D1C00[];
extern s32 D_800E9550;

void func_80047184(s32 arg0) {
    u32* p;

    p = D_800730AC[(s8)D_800D1C00[0xC] * 2 + (s8)D_800D1C00[0xD]];
    D_800E9550 = arg0;
    if (p != 0) {
        if (arg0 != 0) {
            *p |= 0x19FFFF;
        } else {
            *p &= ~0x19FFFF;
        }
    }
}
