#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FAE58_ovl55(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.unk57 = 0;
        *(s16*)&D_8009A1F8.padA1[0xB2 - 0xA1] = 0;
        D_8009A1F8.unkB6 = 0x100;
        D_8009A1F8.unkF4 = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
