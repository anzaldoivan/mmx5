#include "types.h"

extern s32 D_8009A420;
extern u16 D_80093E68;
extern u16 D_800D50DE;
extern u16 D_8009A42E;

void func_800FADFC_ovl58(UnkObj* arg0) {
    if ((D_8009A420 & 1) == 0) {
        D_800D50DE += 1;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
    }
    if (D_800D50DE >= 0x1F) {
        arg0->unk1++;
        arg0->unk4 = 0;
    }
}
