#include "types.h"
#include "mmx5/ovl53.h"
#include "mmx5/globals.h"

extern u8 D_800D1F3C;
extern X4_BackgroundObj D_8009A24C[3];
extern s32 D_80093DD0[];

void func_800FA828_ovl53(UnkObj* arg0) {
    if (D_800D1F3C == 2) {
        D_8009A24C[0].unk3 = 0;
        ((s32(*)())load_palette)(0x60, D_800FAD9C_ovl53, 0x10);
        ((s32(*)())load_palette)(0x70, D_800FB19C_ovl53, 0x10);
        D_80093DD0[2] = 0xFFFF;
        D_80093DD0[3] = 0xFFFF;
        D_80093DD0[4] = 0xFFFF0000;
        arg0->unk6 = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
