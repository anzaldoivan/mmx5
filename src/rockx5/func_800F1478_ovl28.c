#include "types.h"

extern void (*D_800FDA78_ovl28[])(u8*);

#define SCR (*(u8**)0x1F80004C)

void func_800F1478_ovl28(u8* a0) {
    D_800FDA78_ovl28[(s8)a0[6]](a0);
    SCR[0x8A] = a0[6];
    SCR[0x8B] = a0[0x7C];
    *(u16*)(SCR + 0x8E) = *(u16*)(a0 + 0xE);
    *(s32*)(SCR + 0x90) = *(s32*)(a0 + 0x24);
    *(s32*)(SCR + 0x94) = *(s32*)(a0 + 0x2C);
}
