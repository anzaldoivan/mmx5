#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FA32C_ovl48(UnkObj* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0;
        p[0x57] = 1;
        p[0xA0] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
