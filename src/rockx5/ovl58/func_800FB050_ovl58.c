#include "types.h"

extern u8 D_80091C44;
extern D_8009A1F8_t D_8009A1F8;

void func_800FB050_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.pad0[3] = 1;
        D_8009A1F8.unkA = 0;
        D_8009A1F8.unkE = 0xE0;
        D_8009A1F8.pad49[0x4C - 0x49] = 1;
        D_8009A1F8.padA1[0xAB - 0xA1] = 0;
        arg0->unk1++;
    }
}
