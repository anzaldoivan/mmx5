#include "types.h"

extern u8 D_800FCCB8_ovl55[];
extern u8 D_800FCAB8_ovl55[];
extern s32 D_800FD2BC_ovl55;

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern s32 func_80016490(s32, s32, void*);

void func_800FB30C_ovl55(u8* e) {
    *(s16*)(e + 4) = 0;
    func_8002C3CC(D_800FCCB8_ovl55, D_800FCAB8_ovl55, 0x100, 0, 0x78);
    func_8002C338(0x90, D_800FCCB8_ovl55, 0x10);
    D_800FD2BC_ovl55 = 0;
    func_80016490(2, 0x53, 0);
    e[1]++;
}
