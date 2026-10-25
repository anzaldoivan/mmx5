#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FD258_ovl01[])(u8*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_800F6BDC_ovl01(u8* a0);

void func_800F6360_ovl01(u8* a0) {
    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        D_800FD258_ovl01[*(s8*)(a0 + 5)](a0);
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
    func_8002D9EC(a0, 0x40, 0x20);
    func_800F6BDC_ovl01(a0);
}
