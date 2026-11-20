#include "types.h"

extern s32 func_800326BC(u8* a0);

void func_800F9180_ovl09(u8* a0) {
    if (*(u16*)(*(u8**)(a0 + 0x7C) + 4) != 0x303) {
        a0[4] = 2;
    } else {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        func_800326BC(a0);
    }
}
