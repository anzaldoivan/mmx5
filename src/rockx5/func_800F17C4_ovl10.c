#include "types.h"

extern s32 func_800F1B88_ovl10(u8* e);

void func_800F17C4_ovl10(u8* e) {
    if (func_800F1B88_ovl10(e) != 0) {
        e[5] = 4;
        e[6] = 0;
    } else if (--*(s16*)(e + 0x7C) == -1) {
        e[5] = 3;
        e[6] = 0;
    }
}
