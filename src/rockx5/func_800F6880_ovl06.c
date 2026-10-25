#include "types.h"

extern void func_8004FD90(u8*, s32, s32, s32);
extern void func_8002D89C(u8*);

void func_800F6880_ovl06(u8* a0) {
    if ((*(u16*)(a0 + 0x80) & 0xF) == 0) {
        func_8004FD90(a0, 1, 0x20, 0x20);
    }
    a0[3] ^= 1;
    if (a0[3] != 0) {
        func_8002D89C(a0);
    }
    if (*(s16*)(a0 + 0x80) == 0) {
        a0[4] = 3;
    } else {
        *(s16*)(a0 + 0x80) = *(s16*)(a0 + 0x80) - 1;
    }
    *(u16*)(a0 + 0x42) &= 0x7FFF;
}
