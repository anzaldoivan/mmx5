#include "types.h"

extern u8 D_8009A1F8[];

void func_800FA1F4_ovl51(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 == 0) {
        p = D_8009A1F8;
        p[0xAB] = 1;
        *(s16*)(p + 0xB2) = 0;
        *(s16*)(p + 0xB6) = 0;
        p[0xF4] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
