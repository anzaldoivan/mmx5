#include "types.h"

extern u8 D_8009A0A0[];
extern s32 func_800317B8(u8* a0);

s32 func_800F2E90_ovl10(u8* a0) {
    u8* p = D_8009A0A0;

    if (((s8*)p)[0xCA] == 0 && func_800317B8(a0) != 0 && ((s8*)p)[0xCA] != 0) {
        return 1;
    }
    return 0;
}
