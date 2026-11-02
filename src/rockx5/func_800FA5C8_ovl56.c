#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A1F8[];
extern u8 D_800D1F3C;
extern u8 D_800FD900_ovl56[];
extern u8 D_800FD700_ovl56[];
extern u8 D_800FDD00_ovl56[];
extern u8 D_800FDB00_ovl56[];
extern u8 D_800FD500_ovl56[];
extern u8 D_800FD300_ovl56[];

void func_800FA5C8_ovl56(u8* arg) {
    if (D_800D1F3C == 2) {
        u8* p = D_8009A1F8;
        *(s16*)(p + 0x62) = 0x500;
        p[0xA0] = 1;
        *(s16*)(arg + 4) = 0;
        func_8002C3CC(D_800FD900_ovl56, D_800FD700_ovl56, 0x100, 0x5A, 0x5A);
        func_8002C338(0x150, D_800FD900_ovl56, 0x10);
        func_8002C3CC(D_800FDD00_ovl56, D_800FDB00_ovl56, 0x100,
                      0x5A - *(s16*)(arg + 4), 0x5A);
        func_8002C338(0xF0, D_800FDD00_ovl56, 0x10);
        func_8002C3CC(D_800FD500_ovl56, D_800FD300_ovl56, 0x100,
                      *(s16*)(arg + 4), 0x5A);
        func_8002C338(0xE0, D_800FD500_ovl56, 0x10);
        arg[1]++;
        func_8002385C(0x67, 0xFF, 0);
    }
}
