#include "types.h"

extern u8 D_80091C44;
extern u8 D_8009A1F8[];

void func_800FA834_ovl57(UnkObj* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8;
        p[0x57] = 1;
        *(s16*)(p + 0x62) = 0x100;
        *(s16*)(p + 0x5E) = 0;
        p[0xA0] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0x200;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
