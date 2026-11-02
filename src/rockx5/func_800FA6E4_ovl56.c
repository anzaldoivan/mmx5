#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern void func_8002385C(s32, s32, s32);
extern u8 D_800FD900_ovl56[];
extern u8 D_800FD700_ovl56[];
extern u8 D_800FDD00_ovl56[];
extern u8 D_800FDB00_ovl56[];
extern u8 D_800FD500_ovl56[];
extern u8 D_800FD300_ovl56[];
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern u8 D_800D50DC;
extern X4_BackgroundObj D_8009A24C[3];
extern s32 D_80093DD0[];

void func_800FA6E4_ovl56(u8* arg) {
    func_8002C3CC(D_800FD900_ovl56, D_800FD700_ovl56, 0x100,
                  0x5A - *(s16*)(arg + 4), 0x5A);
    func_8002C338(0x150, D_800FD900_ovl56, 0x10);
    func_8002C3CC(D_800FDD00_ovl56, D_800FDB00_ovl56, 0x100,
                  0x5A - *(s16*)(arg + 4), 0x5A);
    func_8002C338(0xF0, D_800FDD00_ovl56, 0x10);
    func_8002C3CC(D_800FD500_ovl56, D_800FD300_ovl56, 0x100, *(s16*)(arg + 4),
                  0x5A);
    func_8002C338(0xE0, D_800FD500_ovl56, 0x10);
    if (++*(s16*)(arg + 4) >= 0x5A) {
        D_8009A42C = 0;
        D_80093E66 = 0;
        D_800D50DC = 1;
        D_8009A24C[0].unk3 = 0;
        D_80093DD0[7] = -1;
        D_80093DD0[10] = 0xFFFF;
        arg[1]++;
        func_8002385C(0x68, 0xFF, 0);
    }
}
