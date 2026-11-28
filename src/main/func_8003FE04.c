#include "types.h"

extern s8 D_80074B98[];
extern s8 D_80074B60[];

s32 func_8003FE04(u8* a0, s8 a1) {
    s32 t;
    s32 r;

    if (a0[0xF7] != 0 || ((s8*)a0)[0xA6] != 0) {
        t = (s32)D_80074B98;
    } else {
        t = (s32)D_80074B60;
    }
    r = *(s8*)(a1 + t);
    if (a1 == 0 && (*(s32*)(a0 + 0xFC) & 0x800)) {
        r = 5;
    }
    return r;
}
