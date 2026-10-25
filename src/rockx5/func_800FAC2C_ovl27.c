#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 D_800FD6FC_ovl27[];
extern s32 D_800FD6F8_ovl27[];

void func_800FAC2C_ovl27(u8* arg0) {
    if (*(s8*)(arg0 + 0x45) == 2) {
        func_80016490(2, 0x6B, arg0);
    }
    if (*(s8*)(arg0 + 0x45) == 1) {
        *(s32**)(arg0 + 0x50) = D_800FD6FC_ovl27;
        *(s32**)(arg0 + 0x54) = D_800FD6F8_ovl27;
        *(s32*)(arg0 + 0x68) = 0;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        *(s16*)(arg0 + 0x7C) = 0x28;
        *(s16*)(arg0 + 0x7E) = 6;
        arg0[6]++;
    }
}
