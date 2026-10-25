#include "types.h"

extern void func_8001296C(s32);
extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_8002C1C8(void);
extern u8 D_801007DC_ovl07[];

void func_800F0E6C_ovl07(u8* a0) {
    if ((u16)++ * (u16*)(a0 + 0x9C) >= 6) {
        func_8001296C(3);
        a0[5]++;
        func_8004FD90(a0, 1, 0x20, 0x20);
        func_8004FD90(a0, 1, 0x20, 0x20);
        *(s32*)(a0 + 0x20) = 0xFFFC0000;
        func_8004D4F4(0xB, D_801007DC_ovl07, a0);
        a0[3] = 0;
        *(u16*)(a0 + 0x9C) = 0;
        func_8002C1C8();
    }
}
