#include "types.h"

extern u8 D_80091C38[];

void func_800515F0(u8* arg0) {
    u8* p = D_80091C38;

    if (p[0xD] == 4 && *(s16*)(p + 0xA) < 0x1E) {
        *(s32*)(arg0 + 0x3C) = 0x40000;
        arg0[5]++;
    }
}
