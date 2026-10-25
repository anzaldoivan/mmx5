#include "types.h"

extern u8 D_800D1F3C;
extern u8 D_800FAD9C_ovl53[];
extern u8 D_800FB19C_ovl53[];
extern X4_BackgroundObj D_8009A24C[3];
extern s32 D_80093DD0[];

s32 func_8002C338(s32, void*, s32);

void func_800FA828_ovl53(UnkObj* arg0) {
    if (D_800D1F3C == 2) {
        D_8009A24C[0].unk3 = 0;
        func_8002C338(0x60, D_800FAD9C_ovl53, 0x10);
        func_8002C338(0x70, D_800FB19C_ovl53, 0x10);
        D_80093DD0[2] = 0xFFFF;
        D_80093DD0[3] = 0xFFFF;
        D_80093DD0[4] = 0xFFFF0000;
        arg0->unk6 = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
