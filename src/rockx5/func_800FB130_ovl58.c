#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FB130_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.unk57 = 0;
        D_8009A1F8.padA1[0xAB - 0xA1] = 1;
        *(s16*)&D_8009A1F8.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.unkB6 = 0x500;
        D_8009A1F8.unkF4 = 1;
        arg0->unk1++;
    }
}
