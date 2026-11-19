#include "types.h"

extern u8 func_80030AE4(u8*, s16, s16);

void func_800F09F0_ovl07(u8* obj) {
    s8* p;
    s16 x;

    if (obj[0x15] == 0) {
        x = *(u16*)(obj + 0xA) + (*(s8**)(obj + 0x68))[0];
    } else {
        x = *(u16*)(obj + 0xA) - (*(s8**)(obj + 0x68))[0];
    }
    p = *(s8**)(obj + 0x68);
    obj[0x81] =
        func_80030AE4(obj, x, *(u16*)(obj + 0xE) + p[1] + ((u8*)p)[3] + 1);
}
