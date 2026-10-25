#include "types.h"

extern void func_80016490(s32, s32, void*);
extern u8 D_800FD6F4_ovl27[];
extern u8 D_800FD6F0_ovl27[];

void func_800FAA00_ovl27(u8* a0) {
    if (*(s8*)(a0 + 0x45) == 2) {
        func_80016490(2, 0x6B, a0);
    }
    if (*(s8*)(a0 + 0x45) == 1) {
        *(void**)(a0 + 0x50) = D_800FD6F4_ovl27;
        *(void**)(a0 + 0x54) = D_800FD6F0_ovl27;
        *(s32*)(a0 + 0x68) = 0;
        *(s16*)(a0 + 0x7C) = 0x28;
        a0[6]++;
    }
}
