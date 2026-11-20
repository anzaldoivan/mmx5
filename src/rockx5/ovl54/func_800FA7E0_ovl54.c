#include "types.h"
#include "mmx5/ovl54.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A24C[3];
extern s32 D_80093DD0[];

void func_800FA7E0_ovl54(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A24C[0].unk3 = 0;
        ((s32(*)())func_8002C338)(0x60, D_800FAD54_ovl54, 0x10);
        ((s32(*)())func_8002C338)(0x70, D_800FB154_ovl54, 0x10);
        D_80093DD0[2] = 0xFFFF;
        D_80093DD0[3] = 0xFFFF;
        D_80093DD0[4] = 0xFFFF0000;
        arg0->unk6 = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
