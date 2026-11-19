#include "types.h"

extern u8 D_8009A1F8[];

void func_800FA9AC_ovl46(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8;
    p[0xF4] = 1;
    p[0xA0] = 1;
    *(s32*)(p + 0x5C) += -0xB3333;
    if (*(s32*)(p + 0x5C) <= 0x1F00000) {
        *(s32*)(p + 0x5C) = 0x1F00000;
        e->unk4 = 0;
        e->unk1++;
    }
}
