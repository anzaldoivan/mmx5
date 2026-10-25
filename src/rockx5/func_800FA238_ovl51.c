#include "types.h"

extern u8 D_8009A1F8[];

void func_800FA238_ovl51(UnkObj* arg0) {
    u8* p;

    if (arg0->unk4 < 30) {
        arg0->unk4++;
        return;
    }
    p = D_8009A1F8;
    p[0x57] = 1;
    *(s16*)(p + 0x5E) = 0x140;
    *(s16*)(p + 0x62) = 0x100;
    p[0xA0] = 1;
    arg0->unk4 = 0;
    arg0->unk1++;
}
