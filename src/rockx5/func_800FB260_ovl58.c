#include "types.h"

extern u8 D_80091C44;
extern s32 D_8009A420;
extern u16 D_80093E68;
extern u16 D_800D50DE;
extern u16 D_8009A42E;
extern D_8009A1F8_t D_8009A1F8;

void func_800FB260_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        if ((D_8009A420 & 3) == 0) {
            D_80093E68 += 0x400;
            D_800D50DE += 1;
            D_8009A42E += 0x20;
        }
        if (D_80093E68 == 0x7C00) {
            D_8009A1F8.pad0[3] = 0;
            D_8009A1F8.unk57 = 1;
            D_8009A1F8.unk5E = 0x200;
            D_8009A1F8.unk62 = 0x100;
            D_8009A1F8.unkA0 = 1;
            arg0->unk1++;
            arg0->unk4 = 0;
        }
    }
}
