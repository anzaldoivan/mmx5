#include "types.h"

extern u8 D_800D1C00[];

void func_800F2528_ovl20(u8* arg0) {
    if ((*(s32*)D_800D1C00 & 0xFFFF00) == 0x400) {
        arg0[4]--;
    }
}
