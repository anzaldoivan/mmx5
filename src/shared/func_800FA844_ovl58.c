#include "types.h"
#include "mmx5/globals.h"

extern u8 D_80091C44;

void func_800FA844_ovl58(UnkObj* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8.u[0x3] = 1;
        *(s16*)(D_8009A1F8.u + 0xA) = 0;
        *(s16*)(D_8009A1F8.u + 0xE) = 0;
        D_8009A1F8.u[0x4C] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
