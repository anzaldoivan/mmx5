#include "types.h"

extern u8 D_8009A1F8[];

s32 func_800F7A94_ovl01(s16 x, s16 y, s32 w, s32 h) {
    u8* cam = D_8009A1F8;

    x -= *(u16*)(cam + 0xA);
    y -= *(u16*)(cam + 0xE);
    if ((u16)(x + w) < (u16)(w * 2 + 320) &&
        (u16)(y + h) < (u16)(h * 2 + 240)) {
        return 0;
    }
    return 1;
}
