#include "types.h"

extern u8 D_80091C44;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DE0;
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void func_800FAF28_ovl49(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        D_80093DE0 = 0xFFFF;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
