#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);

void func_800FF3BC_ovl07(u8* p) {
    s16* t = (s16*)(p + 0x7C);

    if (--t[0] == 0) {
        p[4] = 2;
    } else if ((t[1] = *(s16*)(p + 0x7E) - 1) == 0) {
        if (((s8*)p)[2] == 0) {
            func_8004FD90(p, 1, 0x10, 0x20);
        } else {
            func_8004FD90(p, 1, 8, 0x20);
        }
        *(s16*)(p + 0x7E) = 5;
    }
}
