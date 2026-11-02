#include "types.h"

extern void L_800EEFCC_ovl07(u8*, s32);
extern s32 func_80030AE4(u8*, s16, s16);

void func_800EEE64_ovl07(u8* o) {
    s16 x;
    u8* p;
    u16 t;
    s16 y;

    if (o[0x15] == 0) {
        x = *(s16*)(o + 0xA) + **(s8**)(o + 0x68);
    } else {
        x = *(s16*)(o + 0xA) - **(s8**)(o + 0x68);
    }
    p = *(u8**)(o + 0x68);
    y = p[3] + (*(s16*)(o + 0xE) + ((s8*)p)[1]) + 1;
    if (func_80030AE4(o, x, y - 16) == 0x24) {
        t = *(u16*)(o + 0x9C);
        if (t == 0) {
            *(s16*)(o + 0xA) -= 8;
            *(s16*)(o + 0xE) += 0x10;
            L_800EEFCC_ovl07(o, 4);
            *(u16*)(o + 0x9C) = 2;
            *(s16*)(o + 0xE) -= 0x10;
            *(s16*)(o + 0xA) += 8;
            return;
        }
        *(u16*)(o + 0x9C) = t - 1;
        return;
    }
    *(u16*)(o + 0x9C) = 0;
}
