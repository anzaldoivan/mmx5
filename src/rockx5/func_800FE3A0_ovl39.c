#include "types.h"

extern s32 func_800317B8(u8* a0);

void func_800FE3A0_ovl39(u8* a0) {
    u8* p;

    if ((*(u8**)(a0 + 0x7C))[0x47] == 0) {
        func_800317B8(a0);
    }
    p = *(u8**)(a0 + 0x7C);
    if (((s8*)p)[2] == 0) {
        *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA) - 0x38;
    } else {
        *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA) + 0x38;
    }
    *(u16*)(a0 + 0xE) = *(u16*)(*(u8**)(a0 + 0x7C) + 0xE);
    a0[3] = 0;
}
